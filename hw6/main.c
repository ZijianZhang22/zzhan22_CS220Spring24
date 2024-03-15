#include<stdio.h>
#include"dow.h"
#include<stdlib.h>
int main(int argc, char *argv[] ){
int month = atoi(argv[1]);
int day = atoi(argv[2]);
int year = atoi(argv[3]);
int dayy = dow(month,day,year);


if(dayy ==1)
printf("Monday\n");
if(dayy ==2)
printf("Tuesday\n");
if(dayy ==3)
printf("Wednesdayy\n");
if(dayy ==4)
printf("Thursday\n");
if(dayy ==5)
printf("Friday\n");
if(dayy ==6)
printf("Saturday\n");
if(dayy ==0)
printf("Sundayy\n");

return 0;}
