Its a library, not a language. Binding exist for most languages

MPI is based on distributed Mem sys

# Architechtural paradigms of Parallelism

## shared mem sys

all procs share same mem. all can r/w to same mem space

## dist mem sys

procs have private mem.
c1 -> m1 -> interconnect
                ||--MPI
c2 -> m2 -> interconnect

### advantages of MPI 

- Protable
- Flexible
- Compat with shared mem also 

### Alternatives

- OpenCL
- GPU specific
- OpenMP
- pthread and language specific things

# MPI Syntax

Include mpi.h

MPI identifiers start with MPI\_

First, 
```cpp
int MPI_Init(int* argc, char** argv)
```
This starts the program

```cpp
int MPI_Finalize()
```

