#define IMPLEMENT_STUB
#include "common.h"

int solve(const char *data, size_t size) {
    uint32_t a, b;
    a = b = 1;

    uint64_t sum = 0;
    while (b <= 4000000) {
        if (b % 2 == 0) {
            sum += (uint64_t)b; 
        }

        uint32_t temp = b;
        b += a;
        a = temp;
    }

    printf("%" PRIu64 "\n", sum);
    return 0;
}
