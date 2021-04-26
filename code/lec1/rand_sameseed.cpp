#include <cstdlib>
#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char **argv) {
    srand(time(0));
    MPI_Init(&argc, &argv);
    cout << "rand " << rand() << endl;
    return 0;
}
