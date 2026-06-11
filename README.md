# WaveFunctionCollapse
A simple Wave Function Collapse Project

# Vocabulary
**Class** : A tile of the wave function collapse (ex: land, beach or sea).

**Entropy** : The number of possible classes a cell can hold.

**Rule** : The set of possible classes that can be placed around a given class.

**Rule Set** : The set of all rules (so for each class).

**Field** : the grid where the wave function collapse occurs.

# How to use ?

## Step 1: Declare your classes
Declare all your classes using the `class_t class_number(unsigned short id)` function. the `id` should be unique for each class.

Additionally, you can have a `class_t` that holds all of your classes at once. using the `class_t get_any_class(unsigned short tt_nb_of_classes)` function.

*Warning: You can have up to 64 different classes.*

Example:
```c
const class_t SAND = class_number(0);
const class_t SEA = class_number(1);
const class_t LAND = class_number(2);

const class_t ANY = get_any_class(3);
```

## Step 2: Declare your rules and rule set 

Simply declare a `rule_set_t` variable for the rule set, 
```c
rule_set_t rule_set;
```
after that you can declare the rules for each class by declaring a `rule_t` variable. A `rule_t` variable is simply array of 8 `class_t`. Representing which class can lay next to a given class.


# Examples
## Example 1
```
╭────────────────────────────────────────────────────────────────────────────────╮
│░███████████████████████████████████████████████████████████████████████████████│
│░░░█████████████████████████████████████████████████████████████████████████████│
│░░░░████████████████████████████████████████████████████████████████████████████│
│░░░░░███████████████████████████████████████████████████████████████████████████│
│░░░░░░██████████████████████████████████████████████████████████████████████████│
│░░░░░░░░░░░█████████████████████████████████████████████████████████████████████│
│░░░░░░░░░░░░████████████████████████████████████████████████████████████████████│
│░░░░░░░░░░░░░░██████████████████████████████████████████████████████████████████│
│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████████████████████████████████████│
│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████████████████████████████████│
│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████████████████████████████████████│
│ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████████████████████████████████│
│  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████████████│
│   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████████│
│    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████████│
│          ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████│
│                         ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████│
│                                        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│
│                                                        ░░░░░░░░░░░░░░░░░░░░░░░░│
│                                                            ░░░░░░░░░░░░░░░░░░░░│
╰────────────────────────────────────────────────────────────────────────────────╯
```