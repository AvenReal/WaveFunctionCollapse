#include "main.h"
#include "../WaveFunctionCollapse.h"
#include <stdio.h>


int main() {
    printf("main 1\n");
    const class_t SAND = class_number(0);
    const class_t SEA = class_number(1);
    const class_t LAND = class_number(2);
    printf("main 2\n");
    rule_set_t rule_set;

    const rule_t SAND_RULE = {LAND | SAND, LAND | SAND, LAND | SAND, LAND | SAND, SAND | SEA, SAND | SEA, SAND | SEA, SAND | SEA};
    add_rule_to_rule_set(rule_set, SAND, SAND_RULE);
    printf("main 3\n");
    const rule_t SEA_RULE = {SEA | SAND, SEA | SAND, SEA | SAND, SEA | SAND, SEA, SEA, SEA, SEA};
    add_rule_to_rule_set(rule_set, SEA, SEA_RULE);

    const rule_t LAND_RULE = {LAND, LAND, LAND, LAND, LAND | SAND, LAND | SAND, LAND | SAND, LAND | SAND};
    add_rule_to_rule_set(rule_set, LAND, LAND_RULE);

    field_t* field = init_field(&rule_set, 20,10, 3);
    printf("%d", field->height);
    printf("main 4\n");
    collapse(field);
    printf("main 5\n");

    free_field(field);

    return 0;
}
