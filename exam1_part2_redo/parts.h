// CS220 Spring 24  HW 3

#ifndef STRUCTS_PARTS_H
#define STRUCTS_PARTS_H

// 1, Nut, Red, 12.9, London
struct partT {
   int pno;
   char *pname, *color, *location;
   double weight;
};

#define MAX_PARTS 20  // the maximum number of parts in the parts array

// The parts database
struct partsT {
    struct partT *parts[MAX_PARTS];
    unsigned int size;
};


void append_part(struct partsT *inventory,
                 const int pno,     // new part number
                 const char *pname, // new part name
                 const char *color, // new part's color
                 char *location,    // new part's location
                 double weight);    // parts

void print_parts_report(const struct partsT * parts);

#endif //STRUCTS_PARTS_H

