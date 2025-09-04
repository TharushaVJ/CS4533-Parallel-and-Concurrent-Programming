#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cli.h"

static int parse_impl(const char* s) {
    if (strcmp(s, "serial") == 0) return 0;
    if (strcmp(s, "mutex")  == 0) return 1;
    if (strcmp(s, "rwlock") == 0) return 2;
    return -1;
}

void usage(const char* prog_name) {
    fprintf(stderr,
        "Usage: %s --impl [serial|mutex|rwlock] --threads T --n N --m M \\\n"
        "          --mMember F1 --mInsert F2 --mDelete F3 [--seed S]\n"
        "Notes: For serial impl, --threads is ignored. Fractions F1+F2+F3 must equal 1.0\n",
        prog_name);
}

int parse_args(int argc, char** argv, params_t* p) {
    memset(p, 0, sizeof(*p));
    p->impl = -1; p->threads = 1; p->n = 1000; p->m = 10000;
    p->p_member = 0.99; p->p_insert = 0.005; p->p_delete = 0.005; p->seed_provided = 0;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--impl")==0 && i+1<argc) p->impl = parse_impl(argv[++i]);
        else if (strcmp(argv[i], "--threads")==0 && i+1<argc) { p->threads = atoi(argv[++i]); if (p->threads < 1) p->threads = 1; }
        else if (strcmp(argv[i], "--n")==0 && i+1<argc) p->n = atoi(argv[++i]);
        else if (strcmp(argv[i], "--m")==0 && i+1<argc) p->m = atoi(argv[++i]);
        else if (strcmp(argv[i], "--mMember")==0 && i+1<argc) p->p_member = atof(argv[++i]);
        else if (strcmp(argv[i], "--mInsert")==0 && i+1<argc) p->p_insert = atof(argv[++i]);
        else if (strcmp(argv[i], "--mDelete")==0 && i+1<argc) p->p_delete = atof(argv[++i]);
        else if (strcmp(argv[i], "--seed")==0 && i+1<argc) { p->seed = (unsigned)strtoul(argv[++i], NULL, 10); p->seed_provided = 1; }
        else { usage(argv[0]); return -1; }
    }
    if (p->impl < 0) { 
        usage(argv[0]); return -1; 
    }

    double sum = p->p_member + p->p_insert + p->p_delete;
    if (fabs(sum - 1.0) > 1e-6) {
        fprintf(stderr, "Error: fractions must sum to 1.0 (got %.6f)\n", sum);
        return -1;
    }
    return 0;
}