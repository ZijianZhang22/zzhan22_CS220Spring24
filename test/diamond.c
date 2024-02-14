#include "diamond.h"
#include <stdio.h>

void diamond(int n) {
    const char symbol[] = {"\\\"!@#"};// put the symbols in
    int start = 0;
    int gap=n/2; // the middle of the  graph should be n/2 since the leading gaps decrese untill n/2 row and then increase.
    // and the max of leading gap should be this too.
    int number; // the number of a certain symbol should repeat this times in a row

    for(int i=0;i<n;i++){ // repeat n rows here
        if( i<(n+1)/2){
        number=(1+start*2);}
        else{number=number-2;} // determine when the number of symbols should go up or go down

        for(int j=0;j<gap-number/2;j++){
            printf(" ");
        } // print the space due to the number of symbols of a row

        for(int k=0;k<number;k++){
            printf("%c",symbol[start%5]);
        }// print a certain symbol in a row due to the number, and usee the % to get a loop that will
        // Automaticly Loop the all elements in the array.

        printf("\n");
        start++;
    }


}
