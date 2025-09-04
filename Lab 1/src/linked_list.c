#include <stdlib.h>
#include "linked_list.h"

/* Member */
int member(int value, struct list_node_s* head_p){
    struct list_node_s* curr_p = head_p;

    while(curr_p != NULL && curr_p->data < value){
        curr_p = curr_p->next;
    }

    if(curr_p == NULL || curr_p->data > value){
        return 0;
    } else {
        return 1;
    }
}

/* Insert */
int insert(int value, struct list_node_s** head_pp){
    struct list_node_s* curr_p = *head_pp;
    struct list_node_s* pred_p = NULL;
    struct list_node_s* temp_p = NULL;

    while(curr_p != NULL && curr_p->data < value){
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if(curr_p == NULL || curr_p->data > value){
        temp_p = malloc(sizeof(struct list_node_s));
        temp_p->data = value;
        temp_p->next = curr_p;

        if(pred_p == NULL){
            *head_pp = temp_p;
        } else {
            pred_p->next = temp_p;
        }
        return 1;
    } else {
        return 0;
    }
}

/* Delete */
int delete(int value, struct list_node_s** head_pp){
    struct list_node_s* curr_p = *head_pp;
    struct list_node_s* pred_p = NULL;
    
    while(curr_p != NULL && curr_p->data < value){
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if(curr_p != NULL && curr_p->data == value){
        if(pred_p == NULL){
            *head_pp = curr_p->next;
            free(curr_p);
        } else {
            pred_p->next = curr_p->next;
            free(curr_p);
        }
        return 1;
    } else {
        return 0;
    }
}

void list_free(linked_list_s* head) {
    linked_list_s* c = head;
    while (c) { 
        linked_list_s* n = c->next; 
        free(c); c = n; 
    }
    head = NULL;
}

void list_populate_initial(linked_list_s* head, int n, unsigned int* seed) {
    int used = 0; // count of unique keys used
    unsigned char* seen = (unsigned char*)calloc(65536, 1);
    if (!seen) { 
        perror("calloc"); exit(1); 
    }
    while (used < n) {
        int value = (int)(rand_r(seed) & 0xFFFF);
        if (!seen[value]) { 
            seen[value] = 1; 
            list_insert(value, &head); 
            ++used; 
        }
    }
    free(seen);
}