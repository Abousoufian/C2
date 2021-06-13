#include <stdio.h>
#include <stdlib.h>




int main(){
	
	int m = 85;
	int *ab;
	ab = &m;
	
	printf("adres van m = %p\n",&m);
	printf("de waarde van m = %d\n",m);
	
	printf("de adress van ab = %p\n",&ab);
	printf("de waarde van ab = %d\n",*ab);
	
	m = 20;
	ab = &m;
	printf("de waarde van m is veranderd naar 20\n");
	printf("de adress van ab = %p\n",&ab);
	printf("de waarde van ab = %d\n",*ab);
	
	*ab = 50;
	//doordat ab de adress van m heeft zal de waarde van m veranderen als de waarde ab verandert wordt
	
	printf("adres van m = %p\n",&m);
	printf("de waarde van m = %d\n",m);
	
	
	
	
	return 0;
	
}

