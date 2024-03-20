#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parts.h"

/**
 * A function to test calling the append_part function.
 *
 * @return A pointer to the partsT struct that was built
 */
struct partsT * test_append_parts() {
    struct partsT * inventory = malloc(sizeof(struct partsT));
    char pname[1024];
    char location[1024];
    inventory->size = 0;

    strcpy(pname, "Nut");
    strcpy(location, "London");
    append_part(inventory, 1, pname, "Red", location, 12.9);

    strcpy(pname, "Bolt");
    append_part(inventory, 2, pname, "Green", "Paris", 2.9);

    strcpy(pname, "Screw");
    append_part(inventory, 3, pname, "Blue", "Rome", 1.9);

    strcpy(pname, "Washer");
    append_part(inventory, 4, pname, "Yellow", "Berlin", 0.9);

    return inventory;
}

int main() {
    struct partsT * inventory = test_append_parts();
    print_parts_report(inventory);
    return 0;
}

