using Statistics
using MPI
import Base.max

MPI.Init()

comm = MPI.COMM_WORLD
rank = MPI.Comm_rank(comm)
size = MPI.Comm_size(comm)

struct RankValue
    rank::Int64
    value::Float64
end

Base.max(rv1::RankValue, rv2::RankValue) = rv1.value > rv2.value ? rv1 : rv2

a, b, n = 0, 1, 40000
f(x) = x^2

mc_integrate(f, a, b, n) = (b-a)*mean(x->f(a+x*(b-a)), rand(n))

# On each process,
l_int = mc_integrate(f, a, b, n÷size)
#MPI.Send(l_int, 0, 0, comm)

rv_max = MPI.Reduce(RankValue(rank, l_int), max, 0, comm)
g_int = MPI.Reduce(l_int, +, 0, comm)
if rank == 0
    g_int /= size
    println("max=$(rv_max.value) from proc=$(rv_max.rank),\nTotal Integral = $(g_int)")
end
