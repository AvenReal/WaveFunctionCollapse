#include "../WaveFunctionCollapse.h"

int main() {

    //                                     THE TREES
    // ╭────────────────────────────────────────────────────────────────────────────────╮
    // │ ┗┛𜱵┗┳┳┛ ┗┛ 𜱵┗┛┗┛𜱵𜱵┗┳┛┗┳┳┳┛𜱵 𜱵𜱵𜱵𜱵𜱵 ┗┳┛𜱵𜱵𜱵𜱵𜱵┗┛𜱵𜱵𜱵𜱵𜱵 𜱵 𜱵 𜱵𜱵┗┳┳┳┛𜱵𜱵 𜱵𜱵┗┛┗┛ ┗┛┗┛   ┗│
    // │┳┳┳┛ ┗┛𜱵  𜱵 ┗┳┳┳┳┛┗┳┛𜱵𜱵┗┛┗┳┛ ┗┛┗┛┗┳┳┛ ┗┛┗┛┗┳┳┛┗┛┗┛ ┗┳┛𜱵┗┛ ┛┗┛𜱵┗┛𜱵┗┛𜱵𜱵𜱵𜱵 𜱵𜱵    𜱵 │
    // │┛┗┛𜱵𜱵𜱵𜱵┗┳┳┛  ┗┛┗┛𜱵𜱵┗┳┛┗┳┳┳┛𜱵𜱵𜱵𜱵 𜱵𜱵┗┛𜱵 𜱵   𜱵┗┛𜱵𜱵𜱵   𜱵┗┳┛𜱵𜱵𜱵𜱵𜱵𜱵┗┳┳┛𜱵𜱵┗┛┗┛ ┗┛  𜱵 ┗┳│
    // │ 𜱵𜱵┗┛┗┛ ┗┛𜱵𜱵 𜱵  𜱵┗┛ ┗┳┳┛┗┛ ┗┛┗┛ ┗┛𜱵𜱵┗┳┛𜱵𜱵𜱵┗┳┳┛┗┛𜱵𜱵𜱵┗┳┛ ┗┛┗┛┗┛ ┗┛ ┗┛𜱵𜱵𜱵𜱵𜱵𜱵   ┗┳┳┛│
    // │ ┗┛ 𜱵𜱵𜱵   ┗┛𜱵┗┳┳┛ 𜱵  ┗┛𜱵𜱵𜱵𜱵𜱵𜱵𜱵𜱵𜱵𜱵𜱵┗┛ ┗┳┛┗┛𜱵┗┛ 𜱵𜱵┗┛┗┳┛𜱵 𜱵𜱵𜱵𜱵 𜱵  𜱵𜱵𜱵 ┗┛┗┛┗┛𜱵 𜱵 ┗┛𜱵│
    // │𜱵  𜱵┗┛┗┳┳┳┳┳┛𜱵┗┛𜱵𜱵┗┳┳┳┳┛┗┛┗┛┗┛┗┛┗┛  𜱵𜱵┗┳┳┳┛𜱵 𜱵┗┛ 𜱵𜱵┗┳┛ ┗┛┗┛ ┗┳┳┛┗┛ 𜱵𜱵𜱵𜱵𜱵 ┗┳┛   ┗│
    // │┗┳┳┛ 𜱵𜱵┗┛┗┛┗┳┛ 𜱵┗┛ ┗┛┗┛  𜱵𜱵 𜱵𜱵    𜱵𜱵┗┛ ┗┛┗┳┛ ┗┳┳┳┛┗┳┛   𜱵  𜱵𜱵┗┛𜱵𜱵𜱵𜱵┗┛┗┛┗┳┳┛  𜱵𜱵𜱵│
    // │ ┗┛𜱵 ┗┛     ┗┳┳┛ 𜱵 𜱵𜱵𜱵 𜱵𜱵┗┛ ┗┛  𜱵𜱵┗┛  𜱵𜱵𜱵 ┗┳┳┳┛┗┛𜱵𜱵┗┳┳┳┳┛𜱵𜱵┗┛𜱵 ┗┛┗┛  𜱵  ┗┛ 𜱵𜱵┗┛┗│
    // │┳┳┳┛𜱵𜱵𜱵  𜱵𜱵𜱵𜱵┗┛  ┗┳┛┗┛𜱵┗┛  𜱵𜱵 𜱵𜱵┗┛𜱵  𜱵┗┛┗┳┳┛┗┛ 𜱵 ┗┛𜱵┗┛┗┛ ┗┛  ┗┳┳┳┳┳┳┳┛ 𜱵𜱵 𜱵┗┛   │
    // │┗┛┗┳┛┗┛𜱵 ┗┛┗┛ 𜱵𜱵 𜱵┗┳┳┳┛𜱵𜱵  ┗┛𜱵┗┛𜱵 ┗┳┳┛𜱵 𜱵┗┛  𜱵 ┗┳┳┳┛𜱵  𜱵 𜱵𜱵𜱵𜱵 ┗┛┗┛┗┛┗┳┳┛┗┳┛𜱵 𜱵𜱵𜱵│
    // │𜱵𜱵𜱵┗┳┳┳┛𜱵𜱵𜱵𜱵𜱵𜱵┗┛𜱵┗┳┛┗┛ ┗┛𜱵 𜱵 ┗┳┳┛ 𜱵┗┛𜱵┗┳┛𜱵  𜱵┗┳┳┛┗┛ ┗┳┳┛𜱵┗┛┗┛𜱵𜱵  𜱵  𜱵┗┛𜱵𜱵┗┳┛𜱵┗┛┗│
    // │┗┛┗┳┛┗┛ ┗┛┗┛┗┛𜱵𜱵┗┳┛ 𜱵𜱵 𜱵𜱵┗┳┛𜱵𜱵┗┛ 𜱵┗┳┳┛ ┗┳┛𜱵 ┗┳┛┗┳┳┳┳┳┛┗┳┛ 𜱵 𜱵┗┛  ┗┳┳┛𜱵𜱵┗┛𜱵┗┳┛  𜱵│
    // │┳┳┳┛ 𜱵𜱵  𜱵  𜱵 ┗┛𜱵┗┳┳┛┗┳┛┗┳┛𜱵┗┛   ┗┳┛┗┳┳┳┛ ┗┳┳┛ 𜱵┗┛┗┛┗┳┳┛𜱵𜱵┗┳┛ 𜱵 𜱵 ┗┛ ┗┛ 𜱵┗┳┛𜱵𜱵 ┗│
    // │┗┛┗┳┳┛┗┳┳┛𜱵𜱵┗┳┳┳┛𜱵┗┛  ┗ 𜱵┗┳┛ 𜱵   𜱵┗┳┳┛┗┛𜱵 𜱵┗┛𜱵𜱵┗┳┳┳┳┳┛┗┳┛┗┳┛  ┗┳┛       ┗┳┛𜱵┗┛ 𜱵│
    // │𜱵  ┗┛𜱵𜱵┗┛ ┗┛ ┗┛┗┳┛ 𜱵𜱵𜱵𜱵𜱵┗┳┛𜱵𜱵┗┳┳┳┛𜱵┗┛𜱵  ┗┳┛𜱵𜱵┗┛𜱵┗┛┗┛┗┳┳┛𜱵𜱵┗┳┳┳┳┛𜱵  𜱵𜱵    ┗┳┛  𜱵┗│
    // │┛  𜱵 ┗┛𜱵 𜱵𜱵𜱵 𜱵𜱵 ┗┳┳┛┗┛┗┛ ┗┳┛┗┳┛┗┛ ┗┳┳┛   ┗┳┛┗┳┳┛ 𜱵 𜱵𜱵┗┛ ┗┛ ┗┛┗┛ ┗┳┳┛┗┳┳┳┳┳┛𜱵𜱵𜱵┗┳│
    // │┳┳┳┛  𜱵┗┳┛┗┛𜱵┗┛𜱵 ┗┛   𜱵𜱵𜱵𜱵┗┳┳┛ 𜱵   ┗┛   𜱵 ┗┳┳┛┗┳┳┛𜱵┗┛𜱵 𜱵    𜱵 𜱵 𜱵┗┛  ┗┛┗┛┗┳┛┗┛ ┗│
    // │┛┗┛𜱵  ┗┳┛𜱵 𜱵┗┳┳┛ 𜱵𜱵𜱵 𜱵┗┛┗┛𜱵┗┛ 𜱵┗┳┳┳┳┳┳┳┳┛𜱵 ┗┛ 𜱵┗┛ ┗┳┳┛ ┗┳┳┳┳┛𜱵┗┳┛   𜱵 𜱵 𜱵𜱵┗┳┳┳┳┳│
    // │┳┳┳┛𜱵  ┃ ┗┳┛ ┗┛ 𜱵┗┛┗┳┛𜱵𜱵 𜱵┗┳┳┳┛𜱵┗┛┗┛┗┛┗┛ ┗┳┳┳┳┛    ┃┗┳┳┳┛┗┛┗┳┛ ┃ 𜱵  ┗┳┛ ┗┛𜱵┗┛┗┛┗│
    // │┗┛┗┳┛ 𜱵┃ 𜱵┗┳┳┳┳┳┛ 𜱵 ┗┳┛┗┳┛ ┗┛┗┳┛   𜱵  𜱵   ┗┛┗┛𜱵𜱵 𜱵𜱵┃𜱵┗┛┗┳┳┳┳┛𜱵𜱵┃𜱵┗┳┳┳┛ 𜱵  ┗┳┳┳┳┳│
    // ╰────────────────────────────────────────────────────────────────────────────────╯


    const class_t AIR = get_class(0);
    const class_t TRUNK = get_class(1);
    const class_t BRANCHES = get_class(2);
    const class_t L_BRANCH = get_class(3);
    const class_t R_BRANCH = get_class(4);
    const class_t LEAF = get_class(5);

    const short tt_nb_of_classes = 6;

    const class_t ANY = get_any_class(tt_nb_of_classes);

    const class_t HAVE_SOUTH_CONNECTOR = BRANCHES | LEAF;
    const class_t HAVE_NORTH_CONNECTOR = L_BRANCH | R_BRANCH;
    const class_t HAVE_EAST_CONNECTOR = BRANCHES | L_BRANCH;
    const class_t HAVE_WEST_CONNECTOR = BRANCHES | R_BRANCH;

    const class_t DONT_HAVE_SOUTH_CONNECTOR = AIR | L_BRANCH | R_BRANCH;
    const class_t DONT_HAVE_NORTH_CONNECTOR = AIR | LEAF | BRANCHES;
    const class_t DONT_HAVE_EAST_CONNECTOR = AIR | LEAF | R_BRANCH;
    const class_t DONT_HAVE_WEST_CONNECTOR = AIR | LEAF | L_BRANCH;


    rule_set_t rule_set;

    const rule_t AIR_RULE = {
        ANY, DONT_HAVE_SOUTH_CONNECTOR, ANY, DONT_HAVE_EAST_CONNECTOR | TRUNK, DONT_HAVE_WEST_CONNECTOR | TRUNK, ANY,
        DONT_HAVE_NORTH_CONNECTOR, ANY
    };
    add_rule_to_rule_set(rule_set, AIR, AIR_RULE);

    const rule_t TRUNK_RULE = {
        ANY, HAVE_SOUTH_CONNECTOR | TRUNK, ANY, DONT_HAVE_EAST_CONNECTOR, DONT_HAVE_WEST_CONNECTOR, ANY, TRUNK, ANY };
    add_rule_to_rule_set(rule_set, TRUNK, TRUNK_RULE);

    const rule_t BRANCHES_RULE = {
        ANY, DONT_HAVE_SOUTH_CONNECTOR, ANY, HAVE_EAST_CONNECTOR, HAVE_WEST_CONNECTOR, ANY,
        HAVE_NORTH_CONNECTOR | TRUNK, ANY };
    add_rule_to_rule_set(rule_set, BRANCHES, BRANCHES_RULE);

    const rule_t L_BRANCH_RULE = {
        ANY, HAVE_SOUTH_CONNECTOR, ANY, DONT_HAVE_EAST_CONNECTOR, HAVE_WEST_CONNECTOR, ANY, DONT_HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, L_BRANCH, L_BRANCH_RULE);

    const rule_t R_BRANCH_RULE = {
        ANY, HAVE_SOUTH_CONNECTOR, ANY, HAVE_EAST_CONNECTOR, DONT_HAVE_WEST_CONNECTOR, ANY, DONT_HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, R_BRANCH, R_BRANCH_RULE);

    const rule_t LEAF_RULE = {
        ANY, DONT_HAVE_SOUTH_CONNECTOR, ANY, DONT_HAVE_EAST_CONNECTOR, DONT_HAVE_WEST_CONNECTOR, ANY,
        HAVE_NORTH_CONNECTOR, ANY };
    add_rule_to_rule_set(rule_set, LEAF, LEAF_RULE);

    field_t* field = init_field(&rule_set, 80, 20, tt_nb_of_classes);

    char* displayer[] = {" ", "┃", "┳", "┗", "┛", "𜱵"};

    debug_collapse(field, displayer, -1);

    print_field(field, displayer );

    return 0;
}