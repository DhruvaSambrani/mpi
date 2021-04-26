#include <iostream>
#include <mpi.h>

using namespace std;

long sum10() {
    long s = 0;
    for (int i = 1; i < 10; i++)
        s += i;
    return s;
}

long prod10() {
    long s = 1;
    for (int i = 1; i < 10; i++)
        s *= i;
    return s;
}

long sumsq10() {
    long s = 0;
    for (int i = 1; i < 10; i++)
        s += i * i;
    return s;
}

int main(int argc, char **argv) {
    int ierr = MPI_Init(&argc, &argv);
    int procid;
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &procid);
    long sum;
    switch (procid) {
    case 0:
        sum = sum10();
        break;
    case 1:
        sum = prod10();
        break;
    case 2:
        sum = sumsq10();
        break;
    default:
        sum = -1;
        break;
    }
    cout << "Hello from " << procid << ". Value is " << sum << endl;
    MPI_Finalize();
    return 0;
}
