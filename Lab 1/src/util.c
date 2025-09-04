#include "util.h"

double timespec_diff_sec(struct timespec a, struct timespec b) {
    double sec  = (double)(b.tv_sec  - a.tv_sec);
    double nsec = (double)(b.tv_nsec - a.tv_nsec) / 1e9;
    return sec + nsec;
}