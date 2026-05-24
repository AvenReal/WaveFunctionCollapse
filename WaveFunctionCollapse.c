#include "WaveFunctionCollapse.h"
#include <err.h>
#include <stdlib.h>


// ###################################################################################
//                                    CLASS
// ###################################################################################

class_t class_number(const unsigned short i) {
    if (i > 64)
        errx(EXIT_FAILURE, "maximum 64 class, i should be between 0 and 63 and not %d", i );
    return ((unsigned long long)1) << i;
}

int is_in_quantum_state(class_t class) {
    return (class & (class-1)) != 0;
}

// ###################################################################################
//                                    RULES
// ###################################################################################



// ###################################################################################
//                                    CELLS
// ###################################################################################



// ###################################################################################
//                                    FIELD
// ###################################################################################

field_t init_field(const int width, const int height) {
    field_t field = malloc(sizeof(cell_t*) * height);

    for (int i = 0; i < height; ++i) {
        field[i] = malloc(sizeof(cell_t) * width);
    }

    return field;
}
