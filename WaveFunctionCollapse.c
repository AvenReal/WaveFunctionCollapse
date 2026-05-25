#include "WaveFunctionCollapse.h"
#include <err.h>
#include <stdlib.h>


// ###################################################################################
//                                    CLASS
// ###################################################################################

class_t class_number(const unsigned short id) {

    if (id > 64)
        errx(EXIT_FAILURE, "maximum 64 class, i should be between 0 and 63 and not %d", id );

    return ((unsigned long long)1) << id;
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

void add_rule_to_rule_set(rule_set_t rule_set, class_t class, const rule_t rule) {

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

cell_t* get_cell(field_t field, int y, int x, int height, int width) {
    if (y < 0 || y >= height || x < 0 || x >= width)
        return NULL;

    return field[y][x];
}

field_t init_field(const int width, const int height, const int nb_of_classes) {
    field_t field = malloc(sizeof(cell_t*) * height);

    for (int i = 0; i < height; ++i) {
        field[i] = malloc(sizeof(cell_t) * width);
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            field[i][j] = malloc(sizeof(cell_t));
            cell_t* cell = field[i][j];

            cell->northWest = get_cell(field, i - 1, j - 1, height, width);
            cell->north = get_cell(field, i - 1, j, height, width);
            cell->northEast = get_cell(field, i - 1, j + 1, height, width);

            cell->west = get_cell(field, i, j - 1, height, width);
            cell->east = get_cell(field, i, j + 1, height, width);

            cell->southWest = get_cell(field, i + 1, j - 1, height, width);
            cell->south = get_cell(field, i + 1, j, height, width);
            cell->southEast = get_cell(field, i + 1, j + 1, height, width);

            cell->entropy = nb_of_classes;
            cell->classes = (((class_t)1) << nb_of_classes) - 1;
        }
    }

    return field;
}


void free_field(field_t field) {


}

// ###################################################################################
//                                    WFC Algorithm
// ###################################################################################

cell_t** get_min_entropy_cells(field_t field, int height, int width, int* min_entropy) {
    int nb_cell = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (*min_entropy > field[i][j]->entropy) {
                *min_entropy = field[i][j]->entropy;
                nb_cell = 0;
            }
            if (field[i][j]->entropy == *min_entropy) {
                nb_cell++;
            }
        }
    }

    cell_t** cells = malloc(sizeof(cell_t*) * nb_cell);

    int index = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (field[i][j]->entropy == *min_entropy) {
                cells[index] = field[i][j];
                index++;
            }
        }
    }

    return cells;
}


