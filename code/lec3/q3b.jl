using MPI
using Statistics

MPI.Init()

comm = MPI.COMM_WORLD
rank = MPI.Comm_rank(comm)
size = MPI.Comm_size(comm)

a, b, n = -1, 1, 10000
width = b-a

f(x) = sqrt(1-x^2)

mc_integrate(f, a, width, n) = width*mean(x->f(a+x*width), rand(n))

# On each process,
l_int = mc_integrate(f, a+width/size*rank, width/size, n)
print("l_int on process $(rank)= $(l_int)\n")
g_int = MPI.Reduce(l_int, +, 0, comm)

if rank == 0
    println("=============\nTotal Integral = $(g_int*2)")
end
