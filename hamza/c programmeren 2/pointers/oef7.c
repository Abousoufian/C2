#include <stdio.h>
#include <stdlib.h>

int som(short int *getalA, short int *getalB, short int *uitkomst);


int main(){
	
	
	printf("geef 2 getallen\n");
	scanf("%d",&getalA);
	scanf("\n%d",&getalB);
	uitkomst = som(getalA,getalB,uitkomst);
	printf("\n%d",uitkomst);
	
	
	return 0;
	
}

int som(short int *getalA, short int *getalB, short int *uitkomst)
{
	*uitkomst = *getalA + *getalB;
	
}
