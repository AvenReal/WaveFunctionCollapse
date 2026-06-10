#include "../WaveFunctionCollapse.h"

int main() {

    const class_t AIR = class_number(0);
    const class_t TRUNK = class_number(1);
    const class_t BRANCHES = class_number(2);
    const class_t L_BRANCH = class_number(3);
    const class_t R_BRANCH = class_number(4);
    const class_t LEAF = class_number(5);

    const short tt_nb_of_classes = 6;

    const class_t ANY = get_any_class(tt_nb_of_classes);

    const class_t HAVE_SOUTH_CONNECTOR = TRUNK    | BRANCHES | LEAF;
    const class_t HAVE_NORTH_CONNECTOR = TRUNK    | L_BRANCH | R_BRANCH;
    const class_t HAVE_EAST_CONNECTOR  = BRANCHES | L_BRANCH;
    const class_t HAVE_WEST_CONNECTOR  = BRANCHES | R_BRANCH;

    const class_t DONT_HAVE_SOUTH_CONNECTOR = AIR | L_BRANCH | R_BRANCH;
    const class_t DONT_HAVE_NORTH_CONNECTOR = AIR | LEAF | BRANCHES;
    const class_t DONT_HAVE_EAST_CONNECTOR  = AIR | LEAF | TRUNK | R_BRANCH;
    const class_t DONT_HAVE_WEST_CONNECTOR  = AIR | LEAF | TRUNK | L_BRANCH;


    rule_set_t rule_set;

    const rule_t AIR_RULE =      {ANY, DONT_HAVE_SOUTH_CONNECTOR, ANY, DONT_HAVE_EAST_CONNECTOR, DONT_HAVE_WEST_CONNECTOR, ANY, DONT_HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, AIR, AIR_RULE);

    const rule_t TRUNK_RULE =    {ANY,      HAVE_SOUTH_CONNECTOR, ANY, DONT_HAVE_EAST_CONNECTOR, DONT_HAVE_WEST_CONNECTOR, ANY,      HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, TRUNK, TRUNK_RULE);

    const rule_t BRANCHES_RULE = {ANY, DONT_HAVE_SOUTH_CONNECTOR, ANY,                 L_BRANCH,                 R_BRANCH, ANY,      HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, BRANCHES, BRANCHES_RULE);

    const rule_t L_BRANCH_RULE = {ANY,      HAVE_SOUTH_CONNECTOR, ANY, DONT_HAVE_EAST_CONNECTOR,                 BRANCHES, ANY, DONT_HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, L_BRANCH, L_BRANCH_RULE);

    const rule_t R_BRANCH_RULE = {ANY,      HAVE_SOUTH_CONNECTOR, ANY,                 BRANCHES, DONT_HAVE_WEST_CONNECTOR, ANY, DONT_HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, R_BRANCH, R_BRANCH_RULE);

    const rule_t LEAF_RULE =     {ANY, AIR, ANY, DONT_HAVE_EAST_CONNECTOR, DONT_HAVE_WEST_CONNECTOR, ANY,      HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, LEAF, LEAF_RULE);

    field_t* field = init_field(&rule_set, 60, 20, tt_nb_of_classes);

    collapse(field);

    char* displayer[] = {" ", "┃", "┳", "┗", "┛", "𜱵"};
    print_field(field, displayer );

    return 0;
}