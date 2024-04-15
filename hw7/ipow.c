#include <stdio.h>
#include "ipow.h"
#include <stdint.h>
int64_t ipow( int64_t x, int64_t y){
	if(y==0){
		return 1;}
	else if(y%2 == 0){
		return ipow(x,y/2)*ipow(x,y/2);}
	else if(y%2 == 1){
		return ipow(x,y-1)*x;}
}
