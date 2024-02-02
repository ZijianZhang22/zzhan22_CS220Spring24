//
// Created by 张子健 on 2/1/24.
//
#include "stdio.h"
/**
 * a function to determine if the element is in both array
 * @param s1 array one
 * @param s2  array two
 * @param index index that we want to find the thing in array one
 * @return if there is the same element if yes 1 if not 0
 */
int searchsame(const char s1[],const char s2[],int index){
    int index2=0;
    while(s2[index2]!= '\0'){
        if (s1[index]==s2[index2]){
            return 1;
        }
    index2++;}
    return 0;
}
/**
 * try to put all elements both in s1 and s2 into a new array and print all of them.
 * @param s1 array one
 * @param s2 array two
 * @param rslt the array we use to store.
 */
void common(const char s1[], const char s2[], char rslt[]) {
    // delete the data if we used in our last try, because the data will still stay in the array
    int delete=0;
    while(rslt[delete]!='\0'){
        rslt[delete]='\0';
        delete++;
    }
    // search the data one by one to find if the certain data has a brother in s2.
 int searchindex=0;
 int startpoint=0;
 while (s1[searchindex]!='\0'){
     // if in s2 and not in our result array just add it in our result array
     if (searchsame(s1,s2,searchindex)==1 && (searchsame(s1,rslt,searchindex)==0)){
         rslt[startpoint]=s1[searchindex];
         startpoint++;
     }//
     searchindex++;
 } rslt[startpoint]='\0'; // the terminal


}
