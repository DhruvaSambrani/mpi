#include <iostream>
#include <mpi.h>

using namespace std;

void printmatrix(int matrix[6][2], int procid) {
    for (int i = 0; i < 6; i++) {
        cout << matrix[i][procid] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    int matrix[6][2];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            matrix[i][j] = i + 6 * j + 1;
        }
    }
    int ierr = MPI_Init(&argc, &argv);
    int procid;
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &procid);
    printmatrix(matrix, procid);
    MPI_Finalize();
}
