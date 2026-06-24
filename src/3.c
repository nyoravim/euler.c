#define IMPLEMENT_STUB
#include "common.h"

typedef struct data {
    uint64_t n;
    uint64_t last_factor;
    double sqrt_n;
} data_t;

void process_factor(data_t* d, uint64_t factor) {
    while (d->n % factor == 0) {
        d->n /= factor;
        d->last_factor = factor;
    }
}

int solve(const char *data, size_t size) {
    data_t d;
    d.n = 600851475143;
    d.last_factor = 1;
    d.sqrt_n = sqrt(d.n);

    process_factor(&d, 2);

    uint64_t factor = 3;
    while (d.n > 1 && factor <= d.sqrt_n) {
        process_factor(&d, factor);
        factor += 2;
    }

    printf("%" PRIu64 "\n", d.n > 1 ? d.n : d.last_factor);
    return 0;
}
