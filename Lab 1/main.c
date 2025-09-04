#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stddef.h>
#include "include/cli.h"
#include "include/linked_list.h"
#include "include/operations.h"
#include "include/util.h"
#include "include/worker.h"

int main(int argc, char** argv) {
    params_t P;
    if (parse_args(argc, argv, &P) != 0) return 1;

    /* Seed */
    unsigned int seed;
    if (P.seed_provided) seed = P.seed;
    else {
        struct timespec ts; clock_gettime(CLOCK_REALTIME, &ts);
        seed = (unsigned int)(ts.tv_nsec ^ ts.tv_sec);
    }

    /* Init sync (for mutex/rwlock) */
    sync_init(P.impl);

    /* Linked list head */
    list_node_s* head = NULL;

    /* 1) Populate initial list (excluded from timing) */
    list_populate_initial(&head, P.n, &seed);

    /* 2) Pre-generate ops (excluded from timing) */
    operation_t* ops = ops_generate(P.m, P.p_member, P.p_insert, P.p_delete, &seed);
    if (!ops) { perror("malloc ops"); return 1; }

    /* 3) Execute and time only the operations */
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    if (P.impl == 0) execute_ops_serial(&head, ops, (size_t)P.m);
    else             execute_ops_parallel(&head, ops, (size_t)P.m, P.impl, P.threads);

    clock_gettime(CLOCK_MONOTONIC, &t1);
    double elapsed = timespec_diff_sec(t0, t1);

    /* Output */
    const char* impl_name = (P.impl==0?"serial":(P.impl==1?"mutex":"rwlock"));
    printf("{\"impl\":\"%s\",\"threads\":%d,\"n\":%zu,\"m\":%zu,"
           "\"mMember\":%.6f,\"mInsert\":%.6f,\"mDelete\":%.6f,"
           "\"elapsed_sec\":%.9f}\n",
           impl_name, (P.impl==0?1:P.threads), P.n, P.m,
           P.p_member, P.p_insert, P.p_delete, elapsed);

    /* Cleanup */
    free(ops);
    list_free(head);
    sync_destroy(P.impl);
    return 0;
}