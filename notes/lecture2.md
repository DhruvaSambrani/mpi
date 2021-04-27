Buffer

count

type

dest

tag

comm: Communicator holds which procs can communicate

# send and receive

MPI\_Send and MPI\_Recv

```
MPI_Send(buf, count, type, dest, tag, comm)
```
transmits count elements from buff to dest of type type via comm

```
MPI_Recv(buf, count, type, source, tag, comm, status)
```
received count eles to buff from source of tag of type, via comm

```
MPI_Abort(comm, errorcode)
MPI_Barrier(comm) # wait for all procs to complete
```
**Master Node**: does the data collection process AFTER procs finish

```
struct MPI_Status // holds info about status in Recv
```

`MPI_Send` errors on invalid rank



