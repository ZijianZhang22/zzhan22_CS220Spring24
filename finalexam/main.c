#include <stdint.h>
#include <stdio.h>
#include "mod.h"
int main(){
	int64_t vec[]={4,9,2,7,6};
	modall(vec, 3,5);

	printf("%lld\n",vec[0]);
	printf("%lld\n",vec[1]);
	printf("%lld\n",vec[2]); 
	printf("%lld\n",vec[3]); 
	printf("%lld\n",vec[4]); 
	return 1;

}
