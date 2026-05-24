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

int get_class_id(class_t class) {
    return __builtin_ctzll(class);
}

// ###################################################################################
//                                    RULES
// ###################################################################################

void add_rule_to_rule_set(rule_set_t rule_set, class_t class, rule_t rule) {

    int class_id = get_class_id(class);
    for (int i = 0; i < 8; ++i) {
        rule_set[class_id][i] = rule[i];
    }

}

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

void free_field(field_t field) {


}