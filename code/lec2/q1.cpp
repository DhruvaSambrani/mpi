#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    int my_rank, nproc; // My process rank
    MPI_Status status;
    MPI_Init(&argc, &argv);
    int tag = 0;
    int msg;
    int sum = 0;
    // proc
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    if (my_rank == 0) {
        // master

        for (int source = 1; source < nproc; source++) {
            MPI_Recv(&msg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
            sum += msg;
        }
    } else {
        MPI_Send(&my_rank, 1, MPI_FLOAT, 0, tag, MPI_COMM_WORLD);
    }
    if (my_rank == 0) {
        cout << sum;
    }
    MPI_Finalize();
    return 0;
}
