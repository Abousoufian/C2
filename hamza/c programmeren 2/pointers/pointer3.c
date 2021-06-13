#include <stdio.h>
#include <stdlib.h>




int main(){
	int a = 12;
	int b = 5;
	int uitkomst = 0;
	int *pa = &a;
	int *pb = &b;
	int *puitkomst = &uitkomst;
	
	*puitkomst = *pa + *pb;
	
	printf("de uitkomst = %d",uitkomst);
	
	return 0;
	
}

