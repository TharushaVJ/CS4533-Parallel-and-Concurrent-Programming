#include <stdlib.h>
#include <pthread.h>
#include "worker.h"
#include "linked_list.h"
#include "operations.h"

static pthread_mutex_t list_mutex;      //for mutex implementation
static pthread_rwlock_t list_rwlock;    //for read-write lock implementation

void sync_init(int impl){
    if(impl == 1){
        pthread_mutex_init(&list_mutex, NULL);
    } else if(impl == 2){
        pthread_rwlock_init(&list_rwlock, NULL);
    }
}

void sync_destroy(int impl){
    if(impl == 1){
        pthread_mutex_destroy(&list_mutex);
    } else if(impl == 2){
        pthread_rwlock_destroy(&list_rwlock);
    }
}

static void* worker_fn (void* args){
    thread_data_t* t = (thread_data_t*) args;
    for (size_t i = 0; i< t->ops_count; i++){
        operation_t* op = &t->ops[i];
        linked_list_s* head = t->head;

        if (t->impl == 1){  //for mutex
            pthread_mutex_lock(&list_mutex);
            if (op->type == OP_MEMBER){
                (void)member(op->value, head);
            } else if (op->type == OP_INSERT){
                (void)insert(op->value, &head);
            } else if (op->type == OP_DELETE){
                (void)delete(op->value, &head);
            }
            pthread_mutex_unlock(&list_mutex);    
        }

        else if (t->imple == 2){ //for rwlock
            if (op->type == OP_MEMBER){
                pthread_rwlock_rdlock(&list_rwlock)
                (void)member(op->value, head);
                pthread_rwlock_unlock(&list_rwlock);   
            }
            else{
                pthread_rwlock_wrlock(&list_rwlock);
                if (op->type == OP_INSERT){
                    (void)insert(op->value, &head);
                } else if (op->type == OP_DELETE){
                    (void)delete(op->value, &head);
                }
                pthread_rwlock_unlock(&list_rwlock);
            }
        }

        else{   //for serial
            if (op->type == OP_MEMBER){
                (void)member(op->value, head);
            } else if (op->type == OP_INSERT){
                (void)insert(op->value, &head);
            } else if (op->type == OP_DELETE){
                (void)delete(op->value, &head);
            }
        }
    }
    return NULL;
}


void execute_ops_serial(linked_list_s* head, operation_t* ops, size_t ops_count){
    thread_data_t t = {
        .head = head,
        .ops = ops,
        .ops_count = ops_count,
        .impl = 0
    };
    worker_fn(&t);
}

void execute_ops_parallel(operation_t* ops, size_t ops_count, int impl, int threads){
    continue;
}