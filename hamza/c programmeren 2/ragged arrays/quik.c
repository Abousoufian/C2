#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int a = 0;
	int b = 0;
	int *ptrA = &a;
	int *ptrB = &b;
	printf("geef een getal\n");
	scanf("%d", &a);
	
	printf("\n");
	
	printf("geef een 2de getal\n");
	scanf("%d", &b);
	
	printf("adres van de variable a: %p\n", &a);
	printf("de waarde van de pointer: %d\n", *ptrA);
	printf("de adres van de pointer: a %p\n", &ptrA);
	
	printf("adres van de variable b: %p\n", &b);
	printf("de waarde van de pointer: %d\n", *ptrB);
	printf("de adres van de pointer: b %p", &ptrB);
	
	
	
	return 0;
	
}

