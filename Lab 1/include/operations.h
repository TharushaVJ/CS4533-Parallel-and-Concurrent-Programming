#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdlib.h>
#include <stddef.h>

typedef enum
{
    OP_MEMBER = 0,
    OP_INSERT = 1,
    OP_DELETE = 2
} optype_t;

typedef struct
{
    optype_t type;
    int value; // 0..65535
} operation_t;

/* Shuffle the operations array using the given seed. */
void ops_shuffle(operation_t *ops, size_t count, unsigned int *seed);

/* Generate m operations with the given proportions and seed. */
operation_t *ops_generate(size_t m, double p_member, double p_insert, double p_delete, unsigned int *seed);

#endif /* OPERATIONS_H */