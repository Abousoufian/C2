#include <stdio.h>
#include <stdlib.h>


int main(){
	
	char atemp[5] = "";
	char btemp[5] = "";
	
	
	printf("geef een getal\n");
	gets(atemp);
	
	printf("geef een 2de getal\n");
	gets(btemp);
	
	int a = atoi(atemp);
	int b = atoi(btemp);
	
	int *ptrA = &a;
	int *ptrB = &b;
	
	printf("de waarde van a via pointer is %d\n", *ptrA);
	printf("de waarde van b via pointer is %d\n", *ptrB);
	
	printf("de adress a is %p\n", &a);
	printf("de adress b is %p\n", &b);
	
	printf("de adress ptrA is %p\n", &ptrA);
	printf("de adress ptrB is %p\n", &ptrB);



	
	
	
	
	return 0;
	
}

