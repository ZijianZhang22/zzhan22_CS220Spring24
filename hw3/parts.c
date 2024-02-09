#include "stdio.h"
#include "parts.h"

/**
 * Load the parts database from the parts.csv file.
 */
void load_parts(struct partsT * parts){
    //raed the file of parts and load
    //into the parts array
    struct partT part;
    int done=0;
    int i =0;
    parts->size=0;
    while(!done){
        int x = scanf("%d, %10[^,], %10[^,], %lg, %10s",
                      &part.pno, &part.pname, &part.color, &part.weight, &part.location);
        if(x==EOF)
        {done=1;}
        else if(x==5){
            // TODO make sure x is also 5, the number of values read
            parts->parts[i]=part;
            parts->size=parts->size+1;

            i++;}
    }
}
/*
 *   Print a parts report neatly formatted exactly like below.

    PNO | Name      | Color     | Weight    | Location
    ====|===========|===========|===========|==========
    1   | Nut       | Red       | 12.9      | London
    2   | Bolt      | Green     | 17.8      | Paris
    3   | Screw     | Blue      | 17.1      | Oslo
    4   | Screw     | Red       | 14.02     | London
    5   | Cam       | Blue      | 12.78     | Paris
    6   | Cog       | Red       | 19.2      | London
 */
/**
 * to print  the whole database like what  the above requires
 *
 * @param parts a pointer to our partsT strcut
 */
void print_parts_report(const struct partsT * parts){
    printf("PNO | Name      | Color     | Weight    | Location\n");
    printf("====|===========|===========|===========|==========\n");
    unsigned int i = 0;
    while(i<parts->size){
        printf("%-3d | %-9s | %-9s | %-9g | %-9s\n",
               parts->parts[i].pno,
               parts->parts[i].pname,
               parts->parts[i].color,
               parts->parts[i].weight,
               parts->parts[i].location);
        i++;
    }
    printf("====|===========|===========|===========|==========\n");
}

/*
 * Find the part in parts searching by the part number.
 * Return a pointer to the part and NULL if not found.
 */
struct partT * find(int pno, struct partsT *parts) {
    if( pno-1>parts->size || pno-1<0){
        return NULL;
    }
    else{
        struct partT *p = &(parts)->parts[pno-1];
        return p;
    }
}

/*
 * Print a single part.
 * Example:
 * (PNO) 3 | (NAME) Screw | (COLOR) Blue | (WEIGHT) 17.1 | (LOCATION) Oslo
 */
void print_part(const struct partT *part){
    printf("(PNO) %d | (NAME) %s | (COLOR) %s | (WEIGHT) %g | (LOCATION) %s\n",part->pno,part->pname,part->color,part->weight,part->location);
}
/*
 * Insert a part into the parts array by part number in its proper location
 * ordered by the part number.
 *
 * preconditions:
 *      1) You can assume that the parts array is big enough to hold the new part.
 *      2) You can assume that the part does not already exist in the parts array.
 *
 * Hint: you need to make room for the new part by shifting parts.
 */