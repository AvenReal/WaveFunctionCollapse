#include "WaveFunctionCollapse.h"
#include <err.h>
#include <stdlib.h>


// ###################################################################################
//                                    CLASS
// ###################################################################################

class_t class_number(const unsigned short id) {

    if (id > 64)
        errx(EXIT_FAILURE, "WaveFunctionCollapse.c -> class_number() -> maximum 64 class, id should be between 0 and 63 and not %d", id );

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

class_t get_rules(class_t classes, rule_set_t rule_set, short direction) {

    class_t result = 0;
    for (int i = 0; classes > 0; i++) {
        if (classes % 2)
            result |= rule_set[get_class_id(((class_t) 1) << i)][direction];

        classes >>= 1;
    }

    return result;
}

// ###################################################################################
//                                    CELLS
// ###################################################################################



// ###################################################################################
//                                    FIELD
// ###################################################################################

cell_t* get_cell(grid_t grid, int y, int x, int height, int width) {
    if (y < 0 || y >= height || x < 0 || x >= width)
        return NULL;

    return grid[y][x];
}

field_t* init_field(rule_set_t* rule_set, const int width, const int height, const short tt_nb_of_classes) {
    field_t* field = malloc(sizeof(field_t));

    field->height = height;
    field->width = width;
    field->tt_nb_of_classes = tt_nb_of_classes;

    field->grid = malloc(sizeof(cell_t*) * height);
    if (field->grid == NULL)
        errx(EXIT_FAILURE, "WaveFunctionCollapse.c -> init_field() -> field->grid malloc failed!");

    for (int i = 0; i < height; ++i) {
        field->grid[i] = malloc(sizeof(cell_t) * width);
        if (field->grid[i] == NULL)
            errx(EXIT_FAILURE, "WaveFunctionCollapse.c -> init_field() -> field->grid[i] malloc failed!");
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            field->grid[i][j] = malloc(sizeof(cell_t));
            cell_t* cell = field->grid[i][j];

            cell->neighbours[NorthWest] = get_cell(field->grid, i - 1, j - 1, height, width);
            cell->neighbours[North] = get_cell(field->grid, i - 1, j, height, width);
            cell->neighbours[NorthEast] = get_cell(field->grid, i - 1, j + 1, height, width);

            cell->neighbours[West] = get_cell(field->grid, i, j - 1, height, width);
            cell->neighbours[East] = get_cell(field->grid, i, j + 1, height, width);

            cell->neighbours[SouthWest] = get_cell(field->grid, i + 1, j - 1, height, width);
            cell->neighbours[South] = get_cell(field->grid, i + 1, j, height, width);
            cell->neighbours[SouthEast] = get_cell(field->grid, i + 1, j + 1, height, width);

            cell->entropy = tt_nb_of_classes;
            cell->classes = (((class_t)1) << tt_nb_of_classes) - 1;
        }
    }
    
    field->rule_set = rule_set;
    return field;
}


void free_field(field_t* field) { // TODO


}

// ###################################################################################
//                                    WFC Algorithm
// ###################################################################################

cell_t* get_random_min_entropy_cell(field_t* field) {
    int min_entropy = 64;
    int nb_cell_min_entropy = 0;

    for (int i = 0; i < field->height; ++i) {
        for (int j = 0; j < field->width; ++j) {

            if (min_entropy > field->grid[i][j]->entropy) {
                min_entropy = field->grid[i][j]->entropy;
                nb_cell_min_entropy = 0;
            }

            if (min_entropy == nb_cell_min_entropy) {
                nb_cell_min_entropy++;
            }
        }
    }

    cell_t** candidate_cells = malloc(sizeof(cell_t*) * nb_cell_min_entropy);

    int index = 0;
    for (int i = 0; i < field->height; ++i) {
        for (int j = 0; j < field->width; ++j) {
            if (field->grid[i][j]->entropy) {
                candidate_cells[index] = field->grid[i][j];
                index++;
            }
        }
    }

    cell_t* random_cell = candidate_cells[rand() % nb_cell_min_entropy];
    free(candidate_cells);

    return random_cell;
}

class_t get_random_class(class_t classes, short tt_nb_of_classes) {
    class_t max_class = ((class_t)1) << tt_nb_of_classes;

    int nb_of_class = 0;
    for (class_t i = 1; i <= max_class; i <<= 1) {
        if (classes & i) {
            nb_of_class ++;
        }
    }
    class_t* possible_classes = malloc(sizeof(class_t) * nb_of_class);

    int index = 0;
    for (class_t i = 1; i <= max_class; i <<= 1) {
        if (classes & i) {
            possible_classes[index] = i;
            index++;
        }
    }

    class_t result = possible_classes[rand() % nb_of_class];
    free(possible_classes);

    return result;
}

class_t get_possible_neighbours(class_t classes, direction_t direction, rule_set_t* rule_set, short tt_nb_of_classes) {
    class_t max_class = ((class_t) 1 ) << tt_nb_of_classes;
    class_t result = 0;

    for (class_t i = 1; i <= max_class; i <<= 1) {
        if (i & classes) {
            result |= (*rule_set)[get_class_id(i)][direction];
        }
    }

    return result;
}

short get_entropy(class_t class)
{
    short entropy = 0;
    while(class > 0)
    {
        entropy += (class & 1);
        class >>= 1;
    }
    
    return entropy;
}

void collapse_cell(cell_t* cell, class_t possible_neighbours, rule_set_t* rule_set, short tt_nb_of_classes) {
    if(cell == NULL || cell->entropy == 1 || (cell->classes & possible_neighbours) == cell->classes)
        return;

    if ((cell->classes & possible_neighbours) == 0)
        errx(EXIT_FAILURE, "WaveFunctionCollapse.c -> collapse_cell() -> cell has no possible class to collapse");

    cell->classes = cell->classes & possible_neighbours;
    cell->entropy = get_entropy(cell->classes);
}

void collapse(field_t* field) {

    cell_t* cell_to_collapse = get_random_min_entropy_cell(field);
    class_t random_class = get_random_class(cell_to_collapse->classes, field->tt_nb_of_classes);

    cell_to_collapse->classes = random_class;
    cell_to_collapse->entropy = 1;

    for (direction_t d = 0; d < NB_DIRECTIONS; d++) {
        class_t possible_neighbours = get_possible_neighbours(random_class, d, field->rule_set, field->tt_nb_of_classes);

    }
}

