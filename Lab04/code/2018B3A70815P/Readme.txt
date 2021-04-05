README - Lab 04
Files :
1. mymem.h
2. mymem.c
3. linkedlist.h
4. cycle.h
5. cycle1.c
6. cycle2.c
7. testlscycle.c
8. output.csv
9. output.xlsx
Commands were run in the following order
> gcc -c mymem.c
> gcc -c cycle1.c
> gcc -c cycle2.c
> gcc -c testlscycle.c
> gcc -o exe1 testlscycle.o cycle1.o mymem.o
> gcc -o exe2 testlscycle.o cycle2.o mymem.o
> ./exe1 10000000
> ./exe1 10000000
> ./exe1 10000000
> ./exe1 20000000
> ./exe1 20000000
> ./exe1 20000000
> ./exe1 30000000
> ./exe1 30000000
> ./exe1 30000000
> ./exe1 40000000
> ./exe1 40000000
> ./exe1 40000000
> ./exe1 50000000
> ./exe1 50000000
> ./exe1 50000000
> ./exe1 60000000
> ./exe1 60000000
> ./exe1 60000000
> ./exe1 70000000
> ./exe1 70000000
> ./exe1 70000000
output.csv contains the output from running the executable
This is then converted to xlsx
This data was then used to find the running time complexity of each function.
