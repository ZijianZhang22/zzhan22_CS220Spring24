// CS220 Spring 24 HW 3
#ifndef STRUCTS_PARTS_H
#define STRUCTS_PARTS_H
// 1, Nut, Red, 12.9, London
struct partT {
    int pno;
    char pname[10];
    char color[10];
    double weight;
    char location[20];
};
#define MAX_PARTS 20 // the maximum number of parts in the parts array
// The parts database
struct partsT {
    struct partT parts[MAX_PARTS];
    unsigned int size;
};
/**
* Load the parts database from the parts.csv file.
*/
void load_parts(struct partsT * parts);
/*
* Print a parts report neatly formatted exactly like below.
PNO | Name | Color | Weight | Location
====|===========|===========|===========|==========
1 | Nut | Red | 12.9 | London
2 | Bolt | Green | 17.8 | Paris
3 | Screw | Blue | 17.1 | Oslo
4 | Screw | Red | 14.02 | London
5 | Cam | Blue | 12.78 | Paris
6 | Cog | Red | 19.2 | London
*/
void print_parts_report(const struct partsT * parts);
/*
* Find the part in parts searching by the part number.
* Return a pointer to the part and NULL if not found.
*/
struct partT * find(int pno, struct partsT *parts);
/*
* Print a single part.
* Example:
* (PNO) 3 | (NAME) Screw | (COLOR) Blue | (WEIGHT) 17.1 | (LOCATION) Oslo
*/
void print_part(const struct partT *part);
/*
* Insert a part into the parts array by part number in its proper location
* ordered by the part number.
*
* preconditions:
* 1) You can assume that the parts array is big enough to hold the new part.
* 2) You can assume that the part does not already exist in the parts array.
*
* Hint: you need to make room for the new part by shifting parts.
*/
void insert_part(const struct partT *part, struct partsT *parts);
/*
* Delete a part from the parts array by part number.
*
* preconditions:
* You can assume that the part exists in the parts array.
*
* Hint: Shift parts left.
*
*/
void delete_part(int pno, struct partsT *parts);

#endif //STRUCTS_PARTS_H

