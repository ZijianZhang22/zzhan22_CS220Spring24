//
// Created by 张子健 on 3/7/24.
//

#include <stdlib.h>
#include "float2bin.h"
#include <stdio.h>
char *float2bin(double f){
    char *binary = (char *)malloc(65);
    for(int i=0; i<64;i++){
        f=f*2;
        if(f>1){
            binary[i]= '1';
            f=f-1;
        }
        else if(f<1){
            binary[i]= '0';
        }
        else if(f==1){
            binary[i]='1';
            binary[i+1]='\0';
            return binary;
        }
    }
    binary[64]='\0';
    return binary;

}
