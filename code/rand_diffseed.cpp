#include <cstdlib>
#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int procid;
    MPI_Comm_rank(MPI_COMM_WORLD, &procid);
    srand(procid + 1);
    cout << "rand " << rand() << " from procid " << procid << endl;
    MPI_Finalize();
    return 0;
}
