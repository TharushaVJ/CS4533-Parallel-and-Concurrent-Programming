#ifndef CLI_H
#define CLI_H

#include <stdlib.h>

typedef struct {
    int impl;              // 0: serial, 1: mutex, 2: rwlock 
    int threads;           // Number of threads (1, 2, or 4)
    size_t n;              // Initial number of nodes in the linked list
    size_t m;              // Number of operations
    double p_member;       // fraction of member operations
    double p_insert;       // fraction of insert operations
    double p_delete;       // fraction of delete operations
    unsigned int seed;     // Seed for random number generation
    int seed_provided;     // Flag to check if seed is provided
} params_t;

int parse_args(int argc, char** argv, params_t* params);
void usage(const char* prog_name);

#endif /* CLI_H */