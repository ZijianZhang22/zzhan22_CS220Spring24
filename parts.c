//
// Created by 张子健 on 2/27/24.
//
#include <stdlib.h>
#include "stdio.h"
#include "parts.h"
#include <string.h>

void print_parts_report(const struct partsT * parts){
    printf("\n");
    printf("PNO | Name      | Color     | Weight    | Location\n");
    printf("====|===========|===========|===========|==========\n");
    unsigned int i = 0;
    while(i<parts->size){
        printf("%-3d | %-9s | %-9s | %-9g | %-9s\n",
               parts->parts[i]->pno,
               parts->parts[i]->pname,
               parts->parts[i]->color,
               parts->parts[i]->weight,
               parts->parts[i]->location);
        i++;
    }
    printf("====|===========|===========|===========|==========\n");
}


void append_part(struct partsT *inventory,
                 const int pno, // new part number
                 const char *pname, // new part name
                 const char *color, // new part's color
                 char *location, // new part's location
                 double weight){
    struct partT *newPart = malloc(sizeof(struct partT));
    newPart->pno = pno;
    newPart->pname = malloc(strlen(pname)*sizeof (char ));
    newPart->color = malloc(strlen(color)*sizeof(char ));
    newPart->location = malloc(strlen(location)*sizeof (char ));
    for(int i =0; pname[i]!='\0';i++){
    newPart->pname[i] =pname[i];};
    for(int i =0; color[i]!='\0';i++){
    newPart->color=color;}
    for(int i =0; location[i]!='\0';i++){
    newPart->location[i] =location[i];}
    newPart->weight = weight;
    inventory->parts[inventory->size] = newPart;
    inventory->size++;
}