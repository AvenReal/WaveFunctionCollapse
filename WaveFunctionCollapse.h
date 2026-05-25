#ifndef WAVEFUNCTIONCOLLAPSE_CLASS_H
#define WAVEFUNCTIONCOLLAPSE_CLASS_H

// ###################################################################################
//                                    CLASS
// ###################################################################################

/**
 * A class is a tile of the wave function collapse
 */
typedef unsigned long long class_t;

class_t class_number(unsigned short id);

int get_class_id(class_t class);

// ###################################################################################
//                                    RULES
// ###################################################################################

/**
 * A rule is the set of possible classes around a given class.
 */
typedef class_t rule_t[8];

/**
 * A rule set is the array that holds all the rules for all classes.
 */
typedef rule_t rule_set_t[64];

void add_rule_to_rule_set(rule_set_t rule_set, class_t class, const rule_t rule);

// ###################################################################################
//                                    CELLS
// ###################################################################################

typedef struct cell {

    struct cell* northWest;
    struct cell* north;
    struct cell* northEast;
    struct cell* west;
    struct cell* east;
    struct cell* southWest;
    struct cell* south;
    struct cell* southEast;


    class_t classes;
    /**
     * The number of classes currently in quantum state in this cell.
     */
    int entropy;
} cell_t;

// ###################################################################################
//                                    FIELD
// ###################################################################################

/**
 * Double array of *cell_t that represent the grid where the wave function collapse occurs.
 */
typedef cell_t*** field_t;

field_t init_field(int width, int height, int nb_of_classes);

void free_field(field_t field);

// ###################################################################################
//                                    WFC Algorithm
// ###################################################################################

cell_t** get_min_entropy_cells(field_t field, int height, int width, int* min_entropy);


#endif //WAVEFUNCTIONCOLLAPSE_CLASS_H
