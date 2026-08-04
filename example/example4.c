#include "../WaveFunctionCollapse.h"

int main()
{
    //                                     THE NOISE
    // ╭────────────────────────────────────────────────────────────────────────────────╮
    // │┓  ┃ ┃ ┃ ┏━━┛ ┏┛ ┏━━┛ ┃   ┗┓     ┃   ┃ ┃ ┃  ┃   ┗┓    ┃ ┏┛    ┏━┓ ┃ ┃  ┗┓ ┗┓ ┃ ┃│
    // │┗━━┛ ┃ ┗━┛   ┏┛  ┃    ┗━┓  ┗━━━┓ ┗┓  ┗━┛ ┗┓ ┗━━┓ ┗━━┓ ┗━┛     ┃ ┃ ┗━┛   ┗┓ ┃ ┗━┛│
    // │    ┏┛     ┏━┛ ┏━┛ ┏━┓  ┗━┓    ┃  ┃       ┃    ┗┓   ┃     ┏━┓ ┃ ┃    ┏━┓ ┃ ┗┓   │
    // │━┓  ┃  ┏━┓ ┃   ┃   ┃ ┗━┓  ┃  ┏━┛  ┃     ┏━┛     ┃ ┏━┛ ┏━┓ ┃ ┃ ┃ ┗━┓  ┃ ┃ ┃  ┗┓  │
    // │ ┗┓ ┃ ┏┛ ┃ ┗━━━┛   ┗┓  ┃  ┗━━┛    ┗━━┓ ┏┛     ┏━┛ ┃  ┏┛ ┃ ┃ ┃ ┗┓  ┃ ┏┛ ┃ ┗━┓ ┃  │
    // │  ┗━┛ ┃  ┃      ┏━┓ ┃  ┃       ┏━┓   ┃ ┃   ┏━━┛   ┃ ┏┛ ┏┛ ┃ ┗┓ ┃  ┃ ┃ ┏┛   ┗━┛  │
    // │     ┏┛ ┏┛ ┏━┓  ┃ ┃ ┃  ┃     ┏━┛ ┃   ┃ ┗━┓ ┃    ┏━┛ ┃ ┏┛  ┃  ┃ ┃  ┗━┛ ┃ ┏━┓   ┏━│
    // │┓    ┃  ┃ ┏┛ ┗┓ ┃ ┃ ┗━━┛ ┏━┓ ┃   ┗┓  ┃   ┃ ┗┓   ┃  ┏┛ ┃  ┏┛ ┏┛ ┗━┓   ┏┛ ┃ ┃ ┏━┛ │
    // │┃  ┏━┛  ┃ ┃   ┃ ┗━┛      ┃ ┗━┛    ┗━━┛   ┗┓ ┃   ┃  ┃ ┏┛  ┃ ┏┛    ┃   ┃ ┏┛ ┃ ┃   │
    // │┛  ┃  ┏━┛ ┗━┓ ┗┓   ┏━┓   ┃            ┏━┓ ┃ ┗━┓ ┃  ┃ ┃   ┃ ┃ ┏━┓ ┗┓  ┃ ┃ ┏┛ ┃ ┏━│
    // │ ┏━┛ ┏┛     ┗┓ ┗━┓ ┃ ┗━━━┛ ┏━━━━━━━┓  ┃ ┃ ┗┓  ┃ ┃ ┏┛ ┗━━━┛ ┃ ┃ ┗┓ ┗━━┛ ┗━┛  ┃ ┃ │
    // │ ┃   ┃  ┏━━┓ ┃   ┗━┛       ┃       ┗━━┛ ┃  ┃  ┗━┛ ┃        ┃ ┗┓ ┗┓        ┏━┛ ┃ │
    // │ ┗━┓ ┗┓ ┃  ┗━┛       ┏━━━┓ ┗┓   ┏━┓     ┃  ┗━┓   ┏┛ ┏━┓ ┏━━┛  ┃  ┃       ┏┛  ┏┛ │
    // │   ┃  ┃ ┗━┓     ┏━┓ ┏┛   ┗┓ ┃  ┏┛ ┗━━┓  ┗━┓  ┗┓ ┏┛  ┃ ┃ ┃   ┏━┛  ┃       ┃ ┏━┛ ┏│
    // │┓  ┗┓ ┗┓  ┗━━━┓ ┃ ┗━┛ ┏━┓ ┗━┛  ┃     ┃    ┗┓  ┗━┛   ┃ ┃ ┃ ┏━┛    ┗┓  ┏━━━┛ ┃   ┃│
    // │┃   ┗┓ ┃      ┃ ┗┓    ┃ ┗┓     ┗┓    ┃ ┏━┓ ┗┓       ┗━┛ ┗━┛  ┏━┓  ┗━━┛     ┗┓  ┃│
    // │┗━━┓ ┃ ┃ ┏━┓ ┏┛  ┗━┓  ┗┓ ┃      ┗━━━━┛ ┃ ┗┓ ┗┓               ┃ ┗━┓      ┏━┓ ┃  ┃│
    // │   ┃ ┃ ┗━┛ ┃ ┃     ┃   ┗━┛ ┏━━┓       ┏┛  ┃  ┗━━━┓    ┏━━━┓ ┏┛   ┃  ┏━┓ ┃ ┗━┛ ┏┛│
    // │┓ ┏┛ ┃     ┃ ┗━━━┓ ┗━┓    ┏┛  ┃ ┏━┓   ┃   ┗━┓    ┃   ┏┛   ┃ ┃  ┏━┛  ┃ ┃ ┗┓   ┏┛ │
    // │┃ ┃  ┗┓    ┗┓    ┗┓  ┗┓ ┏━┛  ┏┛ ┃ ┗┓  ┗━━┓  ┃ ┏━━┛ ┏━┛  ┏━┛ ┗┓ ┃  ┏━┛ ┃  ┗━┓ ┃ ┏│
    // ╰────────────────────────────────────────────────────────────────────────────────╯

    const class_t V_PIPE = get_class(0);
    const class_t H_PIPE = get_class(1);
    const class_t SE_CORNER = get_class(2);
    const class_t SW_CORNER = get_class(3);
    const class_t NE_CORNER = get_class(4);
    const class_t NW_CORNER = get_class(5);
    const class_t AIR = get_class(6);
    const short NB_CLASSES = 7;

    const class_t HAVE_SOUTH_CONNECTOR = V_PIPE | SE_CORNER | SW_CORNER;
    const class_t HAVE_NORTH_CONNECTOR = V_PIPE | NE_CORNER | NW_CORNER;
    const class_t HAVE_EAST_CONNECTOR = H_PIPE | NE_CORNER | SE_CORNER;
    const class_t HAVE_WEST_CONNECTOR = H_PIPE | NW_CORNER | SW_CORNER;

    const class_t DONT_HAVE_SOUTH_CONNECTOR = H_PIPE | NE_CORNER | NW_CORNER | AIR;
    const class_t DONT_HAVE_NORTH_CONNECTOR = H_PIPE | SE_CORNER | SW_CORNER | AIR;
    const class_t DONT_HAVE_EAST_CONNECTOR = V_PIPE | NW_CORNER | SW_CORNER | AIR;
    const class_t DONT_HAVE_WEST_CONNECTOR = V_PIPE | NE_CORNER | SE_CORNER | AIR;

    const class_t ANY = get_any_class(NB_CLASSES);

    rule_set_t rule_set;

    const rule_t V_PIPE_RULE = {
        ANY, HAVE_SOUTH_CONNECTOR, ANY, AIR, AIR, ANY, HAVE_NORTH_CONNECTOR, ANY
    };
    add_rule_to_rule_set(rule_set, V_PIPE, V_PIPE_RULE);

    const rule_t H_PIPE_RULE = {
        ANY, AIR, ANY, HAVE_EAST_CONNECTOR, HAVE_WEST_CONNECTOR, ANY, AIR, ANY
    };
    add_rule_to_rule_set(rule_set, H_PIPE, H_PIPE_RULE);

    const rule_t SE_CORNER_RULE = {
        ANY,
        AIR,
        ANY,
        AIR,
        HAVE_WEST_CONNECTOR ^ SW_CORNER,
        ANY,
        HAVE_NORTH_CONNECTOR ^ NE_CORNER,
        ANY
    };
    add_rule_to_rule_set(rule_set, SE_CORNER, SE_CORNER_RULE);

    const rule_t SW_CORNER_RULE = {
        ANY,
        AIR,
        ANY,
        HAVE_EAST_CONNECTOR ^ SE_CORNER,
        AIR,
        ANY,
        HAVE_NORTH_CONNECTOR ^ NW_CORNER,
        ANY
    };
    add_rule_to_rule_set(rule_set, SW_CORNER, SW_CORNER_RULE);

    const rule_t NE_CORNER_RULE = {
        ANY,
        HAVE_SOUTH_CONNECTOR ^ SE_CORNER,
        ANY,
        AIR,
        HAVE_WEST_CONNECTOR ^ NW_CORNER,
        ANY,
        AIR,
        ANY
    };
    add_rule_to_rule_set(rule_set, NE_CORNER, NE_CORNER_RULE);

    const rule_t NW_CORNER_RULE = {
        ANY,
        HAVE_SOUTH_CONNECTOR ^ SW_CORNER,
        ANY,
        HAVE_EAST_CONNECTOR ^ NE_CORNER,
        AIR,
        ANY,
        AIR,
        ANY
    };
    add_rule_to_rule_set(rule_set, NW_CORNER, NW_CORNER_RULE);

    const rule_t AIR_RULE = {
        ANY,
        DONT_HAVE_SOUTH_CONNECTOR,
        ANY,
        DONT_HAVE_EAST_CONNECTOR,
        DONT_HAVE_WEST_CONNECTOR,
        ANY,
        DONT_HAVE_NORTH_CONNECTOR,
        ANY
    };
    add_rule_to_rule_set(rule_set, AIR, AIR_RULE);

    field_t *field = init_field(&rule_set, 80, 20, NB_CLASSES);

    char *displayer[] = {"┃", "━", "┏", "┓", "┗", "┛", " "};

    collapse(field);

    print_field(field, displayer);

    free_field(field);

    return 0;
}
