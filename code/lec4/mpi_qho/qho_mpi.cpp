#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mpi.h"
using namespace std;

#define L 32   /*  Define no. of total lattice sites */

int main(int argc, char** argv) {
int   my_rank;   /* My process rank           */
int   p;         /* The number of processes   */
int   source;    /* Process sending integral  */
int   dest = 0;  /* All messages go to 0      */
int   tag = 0;

MPI_Status  status;

double DT = 0.5;
double w= 1.0; /* frequency of harmonic oscillator      */ 
int GAP = 100;   
int TOTAL = 1000000 ;
double m = 1.0;
double time_spent = 0.0;
double x[L],x_old[L],y[L],z[L];
double S1,H1,H2,S,acc,local_acc;
int sweeps;
int j=0;
	
int   local_n;   /* The number of processes   */

double local_start,local_end,local_runtime,runtime;


/* Let the system do what it needs to start up MPI */
MPI_Init(&argc, &argv);

/* Get my process rank */
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

/* Find out how many processes are being used */
MPI_Comm_size(MPI_COMM_WORLD, &p);



ofstream f_s_bos, f_data;
f_s_bos.open ("data/s_bos.dat");


f_data.open ("data.dat");


ofstream f_corr_bos[L];


	// for(int TOTAL=10000; TOTAL <= 100000000; TOTAL++)
	// { 

MPI_Barrier(MPI_COMM_WORLD); 

local_start = MPI_Wtime();




local_n = TOTAL/p;  

srand((unsigned)time(NULL)+my_rank*p);

for (int i = 0 ; i < L ; i ++){
x[i] = (float)rand()/(float)RAND_MAX;
}




for (int i = 0; i < L; i++)
{
string s_corr_bos = "data/corr_bos" + to_string(i) + ".txt";
f_corr_bos[i].open(s_corr_bos.c_str());
if (f_corr_bos[i].bad())
{
cout << "ERROR OPENING FILE boson_corr"
<< "\n"
<< flush;
}

}




	
for (sweeps = 0 ; sweeps < local_n ; sweeps ++){
for (int i = 0 ; i < L ; i++){
x_old[i] = x[i];  // Keep a copy of old X's to return if HMC fails //
}

S1 = 0;  
for (int i = 0 ; i < L ; i++){
S1 += (m*0.5*(x[i]-x[(i+L-1)%L])*(x[i]-x[(i+L-1)%L])
+0.5*m*w*w*x[i]*x[i]);  }
	H1=S1;

for (int i = 0 ; i < L ; i++){
x[i] = x[i]+DT*((float)rand()/(float)RAND_MAX-0.5);
}

S1=0;
for (int i = 0 ; i < L ; i++){
S1 += (m*0.5*(x[i]-x[(i+L-1)%L])*(x[i]-x[(i+L-1)%L])
+0.5*m*w*w*x[i]*x[i]);  }  
H2 = S1;

if (log((float)rand()/(float)RAND_MAX) > (H1 - H2)){// HMC Rejected//
for (int i = 0; i < L ; i++)
{
x[i] = x_old[i];
}
j++;
}



if (sweeps%GAP == 0)
{
S1=0;
for (int i = 0 ; i < L ; i++){
S1 += (m*0.5*(x[i]-x[(i+L-1)%L])*(x[i]-x[(i+L-1)%L])
+0.125*m*w*w*x[i]*x[i]);  }
MPI_Reduce(&S1,&S,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
if(my_rank==0){
f_s_bos << S/p << endl ; } 
for (int site = 0; site < L; site++)
{
y[site]=x[0]*x[site];
MPI_Reduce(&y[site],&z[site],1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
if(my_rank==0){
f_corr_bos[site] << z[site]/p << endl;  
}      
}
}
}


local_acc=(sweeps-j)*100.0/sweeps;
MPI_Reduce(&local_acc,&acc,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
local_end = MPI_Wtime();
local_runtime=local_end-local_start;
printf("Runtime for %d processor = %f\n",my_rank,local_runtime);
MPI_Reduce(&local_runtime,&runtime,1,MPI_DOUBLE,
MPI_MAX,0,MPI_COMM_WORLD);
/* Shut down MPI */

if(my_rank==0){
printf("Sweeps = %d \n" ,TOTAL);
printf("Lattice Size = %d ,Average Acceptance = %f\n",L,acc/4);
printf("Maximum Runtime = %f seconds \n",runtime);


f_data << TOTAL << "\t" << runtime << endl;	
}


// 		TOTAL = TOTAL * 10;
// 		TOTAL--;

// }


	MPI_Finalize();
	return 0 ;
}
