#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_s {
    int data;
    struct list_node_s* next;
} list_node_s;

/* Sorted unique list operations (no internal locking) */
int member(int value, struct list_node_s* head_p);
int insert(int value, struct list_node_s** head_pp);
int delete(int value, struct list_node_s** head_pp);

void list_free(void);

/* Populate with n unique keys in [0, 65535]*/
void list_populate_initial(int n, unsigned int* seed);

#endif /* LIST_H */