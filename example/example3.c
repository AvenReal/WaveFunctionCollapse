#include "../WaveFunctionCollapse.h"

int main() {

    //                                     THE BUILDINGS
    // ╭────────────────────────────────────────────────────────────────────────────────╮
    // │       ▅   ▅          ▅      ▅                              ▉ ▉▅                │
    // │       ▉   ▉          ▉      ▉    ▅                         ▉ ▉▉            ▅   │
    // │       ▉   ▉    ▅   ▅ ▉      ▉    ▉        ▅                ▉ ▉▉        ▅   ▉   │
    // │   ▅   ▉   ▉    ▉  ▅▉ ▉      ▉    ▉      ▅ ▉ ▅              ▉ ▉▉ ▅      ▉ ▅ ▉   │
    // │   ▉   ▉   ▉    ▉  ▉▉ ▉      ▉    ▉▅     ▉ ▉ ▉              ▉ ▉▉ ▉      ▉ ▉ ▉   │
    // │   ▉   ▉  ▅▉    ▉  ▉▉ ▉ ▅    ▉  ▅ ▉▉     ▉ ▉ ▉              ▉ ▉▉ ▉      ▉ ▉ ▉   │
    // │  ▅▉  ▅▉  ▉▉    ▉  ▉▉ ▉ ▉    ▉  ▉ ▉▉     ▉ ▉ ▉              ▉ ▉▉ ▉ ▅ ▅  ▉ ▉ ▉   │
    // │  ▉▉ ▅▉▉  ▉▉ ▅▅ ▉  ▉▉ ▉ ▉    ▉  ▉▅▉▉     ▉▅▉ ▉▅       ▅     ▉ ▉▉▅▉ ▉ ▉  ▉ ▉ ▉   │
    // │  ▉▉ ▉▉▉  ▉▉ ▉▉ ▉  ▉▉ ▉ ▉    ▉  ▉▉▉▉     ▉▉▉ ▉▉▉    ▅ ▉     ▉ ▉▉▉▉ ▉ ▉  ▉ ▉ ▉   │
    // │  ▉▉ ▉▉▉  ▉▉ ▉▉▅▉  ▉▉ ▉ ▉    ▉  ▉▉▉▉     ▉▉▉ ▉▉▉    ▉ ▉  ▅▅ ▉ ▉▉▉▉ ▉ ▉  ▉ ▉ ▉   │
    // │ ▅▉▉▅▉▉▉  ▉▉ ▉▉▉▉  ▉▉ ▉ ▉   ▅▉  ▉▉▉▉     ▉▉▉ ▉▉▉    ▉ ▉▅ ▉▉ ▉ ▉▉▉▉ ▉ ▉  ▉ ▉ ▉  ▉│
    // │ ▉▉▉▉▉▉▉  ▉▉ ▉▉▉▉  ▉▉ ▉ ▉   ▉▉  ▉▉▉▉▅    ▉▉▉ ▉▉▉    ▉ ▉▉ ▉▉ ▉ ▉▉▉▉ ▉ ▉  ▉ ▉▅▉  ▉│
    // │▅▉▉▉▉▉▉▉  ▉▉ ▉▉▉▉  ▉▉▅▉ ▉   ▉▉  ▉▉▉▉▉    ▉▉▉ ▉▉▉    ▉ ▉▉ ▉▉ ▉ ▉▉▉▉ ▉ ▉  ▉▅▉▉▉▅ ▉│
    // │▉▉▉▉▉▉▉▉  ▉▉ ▉▉▉▉  ▉▉▉▉ ▉   ▉▉  ▉▉▉▉▉▅   ▉▉▉ ▉▉▉    ▉ ▉▉ ▉▉ ▉ ▉▉▉▉ ▉ ▉  ▉▉▉▉▉▉ ▉│
    // │▉▉▉▉▉▉▉▉  ▉▉▅▉▉▉▉  ▉▉▉▉ ▉▅  ▉▉  ▉▉▉▉▉▉   ▉▉▉ ▉▉▉    ▉▅▉▉ ▉▉ ▉▅▉▉▉▉ ▉ ▉  ▉▉▉▉▉▉ ▉│
    // │▉▉▉▉▉▉▉▉  ▉▉▉▉▉▉▉  ▉▉▉▉ ▉▉ ▅▉▉▅ ▉▉▉▉▉▉   ▉▉▉▅▉▉▉▅ ▅ ▉▉▉▉ ▉▉ ▉▉▉▉▉▉ ▉ ▉▅ ▉▉▉▉▉▉ ▉│
    // │▉▉▉▉▉▉▉▉  ▉▉▉▉▉▉▉  ▉▉▉▉ ▉▉ ▉▉▉▉ ▉▉▉▉▉▉  ▅▉▉▉▉▉▉▉▉ ▉ ▉▉▉▉ ▉▉▅▉▉▉▉▉▉ ▉ ▉▉▅▉▉▉▉▉▉▉▉│
    // │▉▉▉▉▉▉▉▉  ▉▉▉▉▉▉▉ ▉▉▉▉▉▅▉▉ ▉▉▉▉ ▉▉▉▉▉▉  ▉▉▉▉▉▉▉▉▉ ▉▅▉▉▉▉ ▉▉▉▉▉▉▉▉▉ ▉ ▉▉▉▉▉▉▉▉▉▉▉│
    // │▉▉▉▉▉▉▉▉ ▉▉▉▉▉▉▉▉▅▉▉▉▉▉▉▉▉ ▉▉▉▉▅▉▉▉▉▉▉  ▉▉▉▉▉▉▉▉▉ ▉▉▉▉▉▉▅▉▉▉▉▉▉▉▉▉▉▉▅▉▉▉▉▉▉▉▉▉▉▉│
    // │▉▉▉▉▉▉▉▉ ▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉ ▉▉▉▉▉▉▉▉▉▉▉▅▉▉▉▉▉▉▉▉▉▉ ▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉│
    // ╰────────────────────────────────────────────────────────────────────────────────╯

    const class_t AIR = get_class(0);
    const class_t ROOF = get_class(1);
    const class_t BUILDING = get_class(2);

    const short tt_nb_of_classes = 3;
    const class_t ANY = get_any_class(tt_nb_of_classes);

    rule_set_t rule_set;

    const rule_t AIR_RULE = {ANY, AIR, ANY, ANY, ANY, ANY, ANY, ANY};
    add_rule_to_rule_set(rule_set, AIR, AIR_RULE);

    const rule_t ROOF_RULE = {ANY, AIR, ANY, ANY, ANY, ANY, BUILDING, ANY};
    add_rule_to_rule_set(rule_set, ROOF, ROOF_RULE);

    const rule_t BUILDING_RULE = {ANY, BUILDING | ROOF, ANY, ANY, ANY, ANY, BUILDING, ANY};
    add_rule_to_rule_set(rule_set, BUILDING, BUILDING_RULE);


    field_t* field = init_field(&rule_set, 80, 20, tt_nb_of_classes);

    char* displayer[] = {" ", "▅", "▉"};

    debug_collapse(field, displayer, 20);
    collapse(field);
    print_field(field, displayer);
    return 0;
}
