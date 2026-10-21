#include "WaveFunctionCollapse.h"

// ###################################################################################
//                                    CLASSES
// ###################################################################################

class_t get_class(const unsigned short id)
{
    if (id > 64)
        errx(
            EXIT_FAILURE,
            "WaveFunctionCollapse.c -> get_class() -> maximum 64 class, id "
            "should be between 0 and 63 and not %d",
            id
        );

    return ((unsigned long long)1) << id;
}

int get_id_of_class(class_t class) { return __builtin_ctzll(class); }

class_t get_any_class(const unsigned short tt_nb_of_classes)
{
    return ((class_t)(1) << tt_nb_of_classes) - 1;
}

/*
- Function: print_classes
- ----------------------------
-  Prints the specified classes to the terminal using the given displayer.
-
-  classes: The class_t bitmask containing the classes to print.
-  displayer: An array of strings representing the names or representations of the classes.
-  tt_nb_of_classes: The total number of classes.
-
-  Returns: void
 */
void print_classes(class_t classes, char *displayer[], short tt_nb_of_classes)
{
    class_t max_class = get_class(tt_nb_of_classes);
    printf("\"");
    for (class_t class = 1; class <= max_class; class <<= 1)
    {
        if (class & classes)
        {
            printf("%s ", displayer[get_id_of_class(class)]);
        }
    }
    printf("\"");
}

// ###################################################################################
//                                    RULES
// ###################################################################################

void add_rule_to_rule_set(rule_set_t rule_set, class_t class, const rule_t rule)
{
    int class_id = get_id_of_class(class);
    for (int i = 0; i < 8; ++i)
    {
        rule_set[class_id][i] = rule[i];
    }
}

// ###################################################################################
//                                    CELLS
// ###################################################################################

/*
 * Help convert direction do it's string form.
 */
const char *direction_strings[] = {
    "NorthWest", "North", "NorthEast", "West", "East", "SouthWest", "South", "SouthEast"
};

const short NB_OF_DIRECTIONS = 8;

// ###################################################################################
//                                    FIELD
// ###################################################################################

/*
- Function: get_cell
- ----------------------------
-  Safely retrieves a cell from the grid at the specified coordinates.
-
-  grid: The 2D array (grid) of cells.
-  y: The y-coordinate (row) of the cell.
-  x: The x-coordinate (column) of the cell.
-  height: The height of the grid.
-  width: The width of the grid.
-
-  Returns: A pointer to the cell_t at the given coordinates, or NULL if out of bounds.
 */
cell_t *get_cell(grid_t grid, int y, int x, int height, int width)
{
    if (y < 0 || y >= height || x < 0 || x >= width)
        return NULL;

    return grid[y][x];
}

field_t *
init_field(rule_set_t *rule_set, const int width, const int height, const short tt_nb_of_classes)
{
    field_t *field = malloc(sizeof(field_t));

    field->height = height;
    field->width = width;
    field->tt_nb_of_classes = tt_nb_of_classes;

    field->grid = malloc(sizeof(cell_t *) * height);
    if (field->grid == NULL)
        errx(
            EXIT_FAILURE,
            "WaveFunctionCollapse.c -> init_field() -> "
            "field->grid malloc failed!"
        );

    for (int i = 0; i < height; ++i)
    {
        field->grid[i] = malloc(sizeof(cell_t) * width);
        if (field->grid[i] == NULL)
            errx(
                EXIT_FAILURE,
                "WaveFunctionCollapse.c -> init_field() -> "
                "field->grid[i] malloc failed!"
            );
        for (int j = 0; j < width; ++j)
        {
            field->grid[i][j] = malloc(sizeof(cell_t));
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cell_t *cell = field->grid[i][j];

            cell->neighbors[NorthWest] = get_cell(field->grid, i - 1, j - 1, height, width);
            cell->neighbors[North] = get_cell(field->grid, i - 1, j, height, width);
            cell->neighbors[NorthEast] = get_cell(field->grid, i - 1, j + 1, height, width);

            cell->neighbors[West] = get_cell(field->grid, i, j - 1, height, width);
            cell->neighbors[East] = get_cell(field->grid, i, j + 1, height, width);

            cell->neighbors[SouthWest] = get_cell(field->grid, i + 1, j - 1, height, width);
            cell->neighbors[South] = get_cell(field->grid, i + 1, j, height, width);
            cell->neighbors[SouthEast] = get_cell(field->grid, i + 1, j + 1, height, width);

            cell->entropy = tt_nb_of_classes;
            cell->classes = (((class_t)1) << tt_nb_of_classes) - 1;
        }
    }
    field->rule_set = rule_set;
    return field;
}

void print_field(field_t *field, char *displayer[field->width])
{
    printf("╭");
    for (int i = 0; i < field->width; ++i)
    {
        printf("─");
    }
    printf("╮\n");
    for (int i = 0; i < field->height; ++i)
    {
        printf("│");
        for (int j = 0; j < field->width; ++j)
        {
            if (field->grid[i][j]->entropy == 1)
                printf("%s", displayer[get_id_of_class(field->grid[i][j]->classes)]);
            else if (field->grid[i][j]->entropy == 0)
                printf("\033[1;31m🮙\033[1;0m");
            else
                printf("%d", field->grid[i][j]->entropy);
        }
        printf("│\n");
    }
    printf("╰");
    for (int i = 0; i < field->width; ++i)
    {
        printf("─");
    }
    printf("╯\n");
}

void free_field(field_t *field)
{
    for (int i = 0; i < field->height; ++i)
    {
        for (int j = 0; j < field->width; ++j)
        {
            free(field->grid[i][j]);
        }
        free(field->grid[i]);
    }
    free(field->grid);

    free(field);
}

// ###################################################################################
//                                    WFC Algorithm
// ###################################################################################

/*
- Function: get_random_min_entropy_cell
- ----------------------------
-  Finds and returns a random cell with the minimum entropy greater than 1.
-
-  field: The field to search within.
-
-  Returns: A pointer to a randomly selected cell_t with the minimum entropy.
-  Error: Fails if memory allocation for candidate cells fails.
 */
cell_t *get_random_min_entropy_cell(field_t *field)
{
    int min_entropy = 64;
    int nb_cell_min_entropy = 0;
    for (int i = 0; i < field->height; ++i)
    {
        for (int j = 0; j < field->width; ++j)
        {
            short cell_entropy = field->grid[i][j]->entropy;
            if (min_entropy > cell_entropy && cell_entropy > 1)
            {
                min_entropy = cell_entropy;
                nb_cell_min_entropy = 0;
            }

            if (min_entropy == cell_entropy)
            {
                nb_cell_min_entropy++;
            }
        }
    }

    cell_t **candidate_cells = malloc(sizeof(cell_t *) * nb_cell_min_entropy);

    if (candidate_cells == NULL)
        errx(
            EXIT_FAILURE,
            "WaveFunctionCollapse.c -> get_random_min_entropy_cell() -> "
            "candidate_cells malloc failed!"
        );

    int index = 0;
    for (int i = 0; i < field->height; ++i)
    {
        for (int j = 0; j < field->width; ++j)
        {
            if (field->grid[i][j]->entropy == min_entropy)
            {
                candidate_cells[index] = field->grid[i][j];
                index++;
            }
        }
    }
    cell_t *random_cell = candidate_cells[rand() % nb_cell_min_entropy];
    free(candidate_cells);

    return random_cell;
}

/*
- Function: get_random_class
- ----------------------------
-  Selects a single random class from the provided bitmask of classes.
-
-  classes: The class_t bitmask containing the available classes.
-  tt_nb_of_classes: The total number of classes.
-
-  Returns: A class_t containing exactly one randomly selected class.
 */
class_t get_random_class(class_t classes, short tt_nb_of_classes)
{
    class_t max_class = ((class_t)1) << tt_nb_of_classes;
    int nb_of_class = 0;
    for (class_t i = 1; i <= max_class; i <<= 1)
    {
        if (classes & i)
        {
            nb_of_class++;
        }
    }
    class_t *possible_classes = malloc(sizeof(class_t) * nb_of_class);
    int index = 0;
    for (class_t i = 1; i <= max_class; i <<= 1)
    {
        if (classes & i)
        {
            possible_classes[index] = i;
            index++;
        }
    }
    class_t result = possible_classes[rand() % nb_of_class];
    free(possible_classes);
    return result;
}

/*
- Function: get_entropy
- ----------------------------
-  Calculates the entropy (number of set bits) in a class_t bitmask.
-
-  class: The class_t bitmask to evaluate.
-
-  Returns: The calculated entropy as a short.
 */
short get_entropy(class_t class)
{
    short entropy = 0;
    while (class > 0)
    {
        entropy += (class & 1);
        class >>= 1;
    }

    return entropy;
}

/*
- Function: indent
- ----------------------------
-  Creates a string containing a specified number of tab characters.
-
-  n: The number of tabs.
-
-  Returns: A newly allocated string of tabs.
 */
char *indent(short n)
{
    char *res = malloc(n + 1);
    for (int i = 0; i < n; i++)
    {
        res[i] = '\t';
    }
    res[n] = 0;
    return res;
}

/*
- Function: collapse_cell
- ----------------------------
-  Propagates the collapse recursively to neighboring cells based on the rule set.
-
-  cell: The cell that has just been collapsed or reduced in entropy.
-  rule_set: The rules defining valid neighboring classes.
-  tt_nb_of_classes: The total number of classes.
-  debug: An integer indicating the depth of debug indentation, or 0 if disabled.
-  displayer: An array of strings used for debug printing.
-
-  Returns: void
 */
void collapse_cell(
    cell_t *cell, rule_set_t *rule_set, short tt_nb_of_classes, short debug, char *displayer[]
)
{
    if (cell == NULL || cell->classes == 0)
        return;

    const class_t max_class = get_class(tt_nb_of_classes);

    class_t classes = cell->classes;
    for (direction_t d = 0; d < NB_OF_DIRECTIONS; ++d)
    {
        if (cell->neighbors[d] != NULL && cell->neighbors[d]->entropy != 1)
        {
            class_t neighbour_classes = cell->neighbors[d]->classes;
            class_t possibilities = 0;

            for (class_t class = 1; class <= max_class; class <<= 1)
            {
                if (class & classes)
                {
                    possibilities |= (*rule_set)[get_id_of_class(class)][d];
                }
            }

            cell->neighbors[d]->classes &= possibilities;

            if (neighbour_classes != cell->neighbors[d]->classes)
            {
                if (debug)
                {
                    char *ind = indent(debug);
                    printf("%s%s\t| ", ind, direction_strings[d]);
                    free(ind);
                    print_classes(neighbour_classes, displayer, tt_nb_of_classes);
                    printf("\t-> ");
                    print_classes(cell->neighbors[d]->classes, displayer, tt_nb_of_classes);
                    printf("\n");
                }
                cell->neighbors[d]->entropy = get_entropy(cell->neighbors[d]->classes);
                collapse_cell(
                    cell->neighbors[d],
                    rule_set,
                    tt_nb_of_classes,
                    debug ? debug + 1 : debug,
                    displayer
                );
            }
        }
    }
}

/*
- Function: is_collapsed
- ----------------------------
-  Checks if the entire field has been fully collapsed (all cells have entropy <= 1).
-
-  field: The field to check.
-
-  Returns: 1 if fully collapsed, 0 otherwise.
 */
short is_collapsed(field_t *field)
{
    for (int i = 0; i < field->height; ++i)
    {
        for (int j = 0; j < field->width; ++j)
        {
            if (field->grid[i][j]->entropy > 1)
            {
                return 0;
            }
        }
    }

    return 1;
}

/*
- Function: collapse_random_cell
- ----------------------------
-  Picks a random cell with minimum entropy, collapses it to a single class, and propagates.
-
-  field: The field containing the cell to collapse.
-  debug: A flag indicating if debug information should be printed.
-  displayer: An array of strings used for debug printing.
-
-  Returns: void
 */
void collapse_random_cell(field_t *field, short debug, char *displayer[field->tt_nb_of_classes])
{
    cell_t *cell_to_collapse = get_random_min_entropy_cell(field);
    class_t random_class = get_random_class(cell_to_collapse->classes, field->tt_nb_of_classes);

    cell_to_collapse->classes = random_class;
    cell_to_collapse->entropy = 1;
    if (debug)
    {
        printf("%s\n", displayer[get_id_of_class(random_class)]);
    }

    collapse_cell(cell_to_collapse, field->rule_set, field->tt_nb_of_classes, debug, displayer);
}

void collapse(field_t *field)
{
    do
    {
        collapse_random_cell(field, 0, NULL);
    } while (!is_collapsed(field));
}

void debug_collapse(field_t *field, char *displayer[field->tt_nb_of_classes], int steps)
{
    for (int i = 0; i != steps && !is_collapsed(field); ++i)
    {
        collapse_random_cell(field, 1, displayer);
        print_field(field, displayer);
    }
}
