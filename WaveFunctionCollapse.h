#ifndef WAVEFUNCTIONCOLLAPSE_CLASS_H
#define WAVEFUNCTIONCOLLAPSE_CLASS_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

// ###################################################################################
//                                    CLASS
// ###################################################################################

/**
 * A class is a tile of the wave function collapse
 */
typedef unsigned long long class_t;

/**
 * Takes an id (= a unique number between 0 and 63) to create a class_t
 * variable.
 * @param id The UNIQUE id of the class.
 * @return The class_t variable corresponding to the id.
 */
class_t get_class(unsigned short id);

/**
 * Returns the id of the class.
 * @param class The class_t you want the id of.
 * @return The id of the class.
 */
int get_id_of_class(class_t class);

/**
 * Returns the class_t corresponding to all classes together ( CLASS_1 | CLASS_2
 * | ... | CLASS_tt_nb_of_classes ).
 * @param tt_nb_of_classes The number of classes you have.
 * @return CLASS_1 | CLASS_2 | ... | CLASS_tt_nb_of_classes.
 */
class_t get_any_class(unsigned short tt_nb_of_classes);

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

/**
 * As the name suggest, this function add a given rule_t to a rule_set_t for a
 * given class_t
 * @param rule_set
 * @param class
 * @param rule
 */
void add_rule_to_rule_set(rule_set_t rule_set, class_t class, const rule_t rule);

// ###################################################################################
//                                    CELLS
// ###################################################################################

/**
 * Helps convert the relative position in the grid to the index in the
 * rule_set_t array.
 */
typedef enum direction : short
{
    NorthWest = 0,
    North = 1,
    NorthEast = 2,
    West = 3,
    East = 4,
    SouthWest = 5,
    South = 6,
    SouthEast = 7
} direction_t;

/**
 * A cell of the grid
 */
typedef struct cell
{
    /**
     * An array of pointer to the neighbors of the cell?
     */
    struct cell *neighbors[8];

    /**
     * The class_t the cell holds.
     */
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
 * Double array of cell_t pointer that represent the grid where the wave
 * function collapse occurs.
 */
typedef cell_t ***grid_t;

/**
 * Where all the main data are located, including the grid_t, it's width and
 * height, the rule_set_t and the number of classes.
 */
typedef struct field
{
    /**
     * Grid of @code cell_t\endcode size of @code height * width\endcode ;
     */
    grid_t grid;

    /**
     * Width of @code grid\endcode.
     */
    int width;
    /**
     * Height of @code grid\endcode.
     */
    int height;

    /**
     * Number of classes the field_t will hold.
     */
    short tt_nb_of_classes;

    rule_set_t *rule_set;
} field_t;

/**
 * Create and initialize a field_t.
 * @param rule_set The rules that the field_t will use.
 * @param width The width of the grid_t.
 * @param height The height of the grid_t
 * @param tt_nb_of_classes The number of classes the grid_t will hold.
 * @return The initialized field_t.
 */
field_t *init_field(rule_set_t *rule_set, int width, int height, short tt_nb_of_classes);

/**
 * Print the field_t to the terminal.
 * @param field The field to print
 * @param displayer An array of string, the array must have the size of @code
 * field->width\endcode.
 */
void print_field(field_t *field, char *displayer[field->width]);

/**
 * Free the field_t from the memory.
 * @param field the field to free.
 */
void free_field(field_t *field);

// ###################################################################################
//                                    WFC Algorithm
// ###################################################################################

/**
 * Collapse the field_t according to the @code field->rule_set\endcode.
 * @warning Uses the default @code rand()\endcode function so running two times
 * the same code will give the same result.
 * @param field The field to collapse.
 * @warning if any cell contain a class of 0, that means that during collapsing,
 * this cell encountered a situation where no class could be placed.
 */
void collapse(field_t *field);

/**
 * Collapse the field_t according to the @code field->rule_set\endcode. and
 * print each step.
 * @warning Uses the default @code rand()\endcode function so running two times
 * the same code will give the same result.
 * @param field The field to collapse.
 * @param displayer An array of string representing how the field should be
 * printed
 * @param steps The number of collapse step to perform ( < 0 => all)
 * @warning if any cell contain a class of 0, that means that during collapsing,
 * this cell encountered a situation where no class could be placed.
 */
void debug_collapse(field_t *field, char *displayer[field->tt_nb_of_classes], int steps);

#endif // WAVEFUNCTIONCOLLAPSE_CLASS_H
