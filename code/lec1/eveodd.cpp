#include <iostream>
#include <mpi.h>

using namespace std;
int main(int argc, char **argv) {
    int ierr = MPI_Init(&argc, &argv);
    int procid;
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &procid);
    auto eveod = (procid % 2) == 0 ? "even" : "odd";
    cout << "Hello from " << procid << ". I am " << eveod << endl;
    MPI_Finalize();
    return 0;
}
