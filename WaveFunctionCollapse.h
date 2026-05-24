#ifndef WAVEFUNCTIONCOLLAPSE_CLASS_H
#define WAVEFUNCTIONCOLLAPSE_CLASS_H

// ###################################################################################
//                                    CLASS
// ###################################################################################

/**
 * A class is a tile of the wave function collapse
 */
typedef unsigned long long class_t;



class_t class_number(unsigned short i);

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

void update_rule_set(rule_set_t rule_set, class_t, rule_t rule);

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

typedef cell_t **field_t;

field_t init_field(int width, int height);

#endif //WAVEFUNCTIONCOLLAPSE_CLASS_H
