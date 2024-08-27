# Dining Philosophers Problem

This project implements the classic Dining Philosophers problem using `mutex locks` and `semaphores` to minimize the chances of deadlock and ensure that the philosophers don't starve.

## Prerequisites

To compile and run this program, you'll need:

- A C/C++ compiler (e.g., GCC)
- Make (optional, for easier compilation)

## Compilation

You can easily compile the program using the provided Makefile. Simply navigate to the directory where the Makefile exists and enter: :

```bash
make
```

or You can compile the program using `gcc` or any other standard C/C++ compiler:

```bash
gcc -I/headers ./srcs/*
```

## Run
ex. ./program_name 4 410 200 200 \[3\]

- arg1 : number of philosophers
- arg2 : time to die
- arg3 : time to eat
- arg4 : time to sleep
- arg5(optional) : minimum number of meals each philosopher must eat