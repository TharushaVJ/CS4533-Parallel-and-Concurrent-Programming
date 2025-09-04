# Lab 1: Parallel and Concurrent Linked List

## Overview

This project benchmarks a linked list implementation in C under different concurrency models:
- **Serial** (single-threaded)
- **Mutex** (multi-threaded, protected by a mutex)
- **RWLock** (multi-threaded, protected by a read-write lock)

You can control the workload and concurrency via command-line arguments.

## Build Instructions

From the `Lab 1` directory, run:

```sh
make
```

This will build the executable (usually named `lablist`).

## Usage

Run the program with:

```sh
./lablist --impl [serial|mutex|rwlock] --threads T --n N --m M \
		  --mMember F1 --mInsert F2 --mDelete F3 [--seed S]
```

**Arguments:**
- `--impl`: Implementation type (`serial`, `mutex`, or `rwlock`)
- `--threads`: Number of threads (ignored for serial)
- `--n`: Initial number of nodes in the linked list
- `--m`: Number of operations to perform
- `--mMember`, `--mInsert`, `--mDelete`: Fractions for each operation type (must sum to 1.0)
- `--seed`: (Optional) Random seed for reproducibility

**Example:**

```sh
./lablist --impl mutex --threads 4 --n 1000 --m 10000 --mMember 0.99 --mInsert 0.005 --mDelete 0.005
```

## Output

The program prints a JSON summary of the run, including:
- Implementation type
- Thread count
- Operation counts and fractions
- Elapsed time

## Cleaning Up

To remove build artifacts:

```sh
make clean
```
