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



typedef enum direction : short {
    NorthWest = 0,
    North = 1,
    NorthEast = 2,
    East = 3,
    West = 4,
    SouthWest = 5,
    South = 6,
    SouthEast = 7
} direction_t;

typedef struct cell {

    struct cell* neighbours[8];

    class_t classes;
    /**
     * The number of classes currently in quantum state in this cell.
     */
    short entropy;
} cell_t;

// ###################################################################################
//                                    FIELD
// ###################################################################################

/**
 * Double array of *cell_t that represent the grid where the wave function collapse occurs.
 */
typedef cell_t*** grid_t;

typedef struct field {
    grid_t grid;

    int width;
    int height;

    short tt_nb_of_classes;

    rule_set_t* rule_set;
} field_t;

field_t* init_field(rule_set_t* rule_set, int width, int height, short tt_nb_of_classes);

void free_field(field_t* field);

// ###################################################################################
//                                    WFC Algorithm
// ###################################################################################

void collapse(field_t* field);


#endif //WAVEFUNCTIONCOLLAPSE_CLASS_H
