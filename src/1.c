#define IMPLEMENT_STUB
#include "common.h"

int solve(const char* data, size_t size) {
    uint32_t factors[] = { 3, 5 };
    uint32_t limit = 1000;

    uint32_t sum = 0;
    for (uint32_t i = 1; i < limit; i++) {
        for (uint32_t j = 0; j < sizeof(factors) / sizeof(*factors); j++) {
            if (i % factors[j] == 0) {
                sum += i;
                break;
            }
        }
    }

    printf("%" PRIu32 "\n", sum);
    return 0;
}
