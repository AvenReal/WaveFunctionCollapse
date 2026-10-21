#include <assert.h>
#include <stdio.h>
#include "../WaveFunctionCollapse.h"

short get_entropy(class_t class);

int main() {
    printf("Testing get_entropy...\n");

    // Edge case: 0
    assert(get_entropy(0) == 0);

    // Power of 2 (only 1 bit set)
    assert(get_entropy(1) == 1);
    assert(get_entropy(2) == 1);
    assert(get_entropy(4) == 1);
    assert(get_entropy(1ULL << 63) == 1);

    // All bits set
    assert(get_entropy(~0ULL) == 64);

    // Mixed bits
    assert(get_entropy(5) == 2); // 101
    assert(get_entropy(0xF) == 4);
    assert(get_entropy(0x0F0F) == 8);

    printf("All tests passed.\n");
    return 0;
}
