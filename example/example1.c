#include "../WaveFunctionCollapse.h"
#include <stdio.h>


int main() {

    const class_t SEA = class_number(0);
    const class_t SAND = class_number(1);
    const class_t LAND = class_number(2);

    rule_set_t rule_set;

    const rule_t SAND_RULE = {LAND | SAND, LAND | SAND, LAND | SAND, LAND | SAND, SAND | SEA, SAND | SEA, SAND | SEA, SAND | SEA};
    add_rule_to_rule_set(rule_set, SAND, SAND_RULE);

    const rule_t SEA_RULE = {SEA | SAND, SEA | SAND, SEA | SAND, SEA | SAND, SEA, SEA, SEA, SEA};
    add_rule_to_rule_set(rule_set, SEA, SEA_RULE);

    const rule_t LAND_RULE = {LAND, LAND, LAND, LAND, LAND | SAND, LAND | SAND, LAND | SAND, LAND | SAND};
    add_rule_to_rule_set(rule_set, LAND, LAND_RULE);

    field_t* field = init_field(&rule_set, 80,20, 3);


    collapse(field);

    char* displayer[] = {" ", "▒", "█"};

    print_field(field, displayer);

    free_field(field);

    return 0;
}
