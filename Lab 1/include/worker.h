#ifndef WORKER_H
#define WORKER_H

#include <stdlib.h>
#include <pthread.h>
#include <stddef.h>
#include "linked_list.h"
#include "operations.h"


typedef struct {
    list_node_s** head;      // Pointer to the head of the linked list
    operation_t* ops;      // Pointer to the first operation
    size_t ops_count;          // Number of operations
    int impl;               // 0: serial, 1: mutex, 2: rwlock 
} thread_data_t;

/* Handle initializing and destroying Mutex or RWLock depending on impl. */
void sync_init(int impl);
void sync_destroy(int impl);

/* Execute operations in serial or in T threads depending on impl. */
void execute_ops_serial(list_node_s** head, operation_t* ops, size_t ops_count);
void execute_ops_parallel(list_node_s** head, operation_t* ops, size_t ops_count, int impl, int threads);

#endif /* WORKER_H */