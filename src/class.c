#include "class.h"
#include <err.h>
#include <stdlib.h>

class_t class_number(const unsigned short i) {
    if (i > 64)
        errx(EXIT_FAILURE, "maximum 64 class, i should be between 0 and 63 and not %d", i );
    return ((unsigned long long)1) << i;
}

#include "class.h"
