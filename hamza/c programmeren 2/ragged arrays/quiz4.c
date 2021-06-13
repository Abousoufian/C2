#include <stdio.h>
#include <stdlib.h>


int main(){
	
	float getal = -85;
	float *ptr = NULL;
	
	getal = getal * -1;
	ptr = &getal;
	printf("%lf\n", *ptr);

	return 0;
	
}

