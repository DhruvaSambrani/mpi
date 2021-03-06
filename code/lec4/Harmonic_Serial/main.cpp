#include<ctime>
#include <iostream>
#include <fstream>
using namespace std;
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define L 32			// Number of lattice sites
double DT = 0.5;		// Step parameter
double w = 1.0;
int GAP = 10;			// Gap between measurements
int TOTAL = 1000000;		// Total number of sweeps
double m = 1.0;
double time_spent = 0.0;
time_t start, finish;
int
main ()
{
  time_t start = clock ();
  cout << "-----------------------" << endl;
  double x[L], x_old[L];	// x[L]: Position coordinate on descretized lattice along temporal direction
  double S1, H1, H2;
  int sweeps;
  int j = 0;

  for (int i = 0; i < L; i++)
    {
      x[i] = drand48 ();	// random start (hot start). Randomly assigning values to all x's
    }
  ofstream f_s_bos;
  f_s_bos.open ("data-analysis/s_bos.dat");	// Opening s_bos.dat file

  ofstream f_corr_bos[L];
  for (int i = 0; i < L; i++)
    {
      string s_corr_bos = "data-analysis/corr_bos" + to_string (i) + ".txt";
      f_corr_bos[i].open (s_corr_bos.c_str ());	// Opening corr_bos(i) file 
      if (f_corr_bos[i].bad ())
	{
	  cout << "ERROR OPENING FILE boson_corr" << "\n" << flush;
	}

    }

  for (sweeps = 0; sweeps < TOTAL; sweeps++)
    {
      for (int i = 0; i < L; i++)
	{
	  x_old[i] = x[i];	// Keep a copy of old X's to return if MC fails //
	}

      S1 = 0;

//S=(m/2)*(x^dot)**2+(m/2)(w*x)**2

      for (int i = 0; i < L; i++)
	{
	  S1 +=
	    (m * 0.5 * (x[i] - x[(i + L - 1) % L]) *
	     (x[i] - x[(i + L - 1) % L]) + 0.5 * m * w * w * x[i] * x[i]);
	}			//Initial action

      H1 = S1;

      for (int i = 0; i < L; i++)
	{
	  x[i] = x[i] + DT * (drand48 () - 0.5);	//Random shifting of position by parameter DT
	}
      S1 = 0;

      for (int i = 0; i < L; i++)
	{
	  S1 +=
	    (m * 0.5 * (x[i] - x[(i + L - 1) % L]) *
	     (x[i] - x[(i + L - 1) % L]) + 0.5 * m * w * w * x[i] * x[i]);
	}			//Final Action

      H2 = S1;

      if (log (drand48 ()) > (H1 - H2))
	{			// HMC Rejected ! //
	  for (int i = 0; i < L; i++)
	    {
	      x[i] = x_old[i];	// As metropolis test rejected the seep. reassigning previous values to x's
	    }
	  j++;			//Rejection number
	}

      if (sweeps % GAP == 0)	// Storing values after given GAP
	{
	  S1 = 0;
	  for (int i = 0; i < L; i++)
	    {
	      S1 +=
		(m * 0.5 * (x[i] - x[(i + L - 1) % L]) *
		 (x[i] - x[(i + L - 1) % L]) + 0.5 * m * w * w * x[i] * x[i]);
	    }

	  f_s_bos << S1 << endl;	// Storing action

	  for (int site = 0; site < L; site++)
	    {
	      f_corr_bos[site] << x[0] * x[site] << endl;	//Storing Correlator   
	    }
	  //=================================     

	}


    }
  cout << "sweeps   " << sweeps << "    Acceptance rate  " << (sweeps -
							       j) * 100.0 /
    sweeps << endl;
  time_t finish = clock ();
  time_spent += difftime (finish, start) / CLOCKS_PER_SEC;
  cout << "Time spent " << time_spent << "  seconds" << endl;
  cout << "-----------------------" << endl;

  return 0;
}
