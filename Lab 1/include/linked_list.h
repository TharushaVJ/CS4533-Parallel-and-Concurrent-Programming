#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_s {
    int data;
    struct list_node_s* next;
} list_node_s;

int member(int value, struct list_node_s* head_p);
int insert(int value, struct list_node_s** head_pp);
int delete(int value, struct list_node_s** head_pp);

#endif /* LIST_H */