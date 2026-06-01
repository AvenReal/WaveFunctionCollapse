#include "main.h"
#include "../WaveFunctionCollapse.h"
#include <stdio.h>


int main() {
    printf("1\n");
    const class_t SAND = class_number(0);
    const class_t SEA = class_number(1);
    const class_t LAND = class_number(2);
    printf("2\n");
    rule_set_t rule_set;

    const rule_t SAND_RULE = {LAND | SAND, LAND | SAND, LAND | SAND, LAND | SAND, SAND | SEA, SAND | SEA, SAND | SEA, SAND | SEA};
    add_rule_to_rule_set(rule_set, SAND, SAND_RULE);
    printf("3\n");
    const rule_t SEA_RULE = {SEA | SAND, SEA | SAND, SEA | SAND, SEA | SAND, SEA, SEA, SEA, SEA};
    add_rule_to_rule_set(rule_set, SEA, SEA_RULE);

    const rule_t LAND_RULE = {LAND, LAND, LAND, LAND, LAND | SAND, LAND | SAND, LAND | SAND, LAND | SAND};
    add_rule_to_rule_set(rule_set, LAND, LAND_RULE);

    field_t* field = init_field(&rule_set, 20,20, 3);
    printf("4\n");
    collapse(field);
    printf("5\n");
    char* displayer[] = {"░", " ", "█"};
    for(int i = 0; i < field->height; i++)
    {
        for(int j = 0; j < field->width; j++)
        {
            printf("%s", displayer[get_class_id(field->grid[i][j]->classes)]);
        }
        printf("\n");
    }
    printf("6\n");

    free_field(field);

    return 0;
}
