#include <stdio.h>
#include <stdlib.h>




int main(){
	
	int integer = 500;
	double komma_getal = 52.635;
	char character = 'x';
	
	int *p_integer = &integer;
	double *p_komma_getal = &komma_getal;
	char *p_character = &character;
	
	printf("integer = %d\nkomma getal = %lf\ncharacter = %c\n",integer ,komma_getal ,character);
	
	printf("gebruik makend van & operator\n");
	printf("het adress van integer = %p\n",&integer);
	printf("het adress van komma_getal = %p\n",&komma_getal);
	printf("het adress van character = %p\n\n",&character);
	
	printf("gebruik makend van * operator\n");
	printf("de waarde van integer = %d\n",*p_integer);
	printf("de waarde van komma_getal = %lf\n",*p_komma_getal);
	printf("de waarde van character = %c\n\n",*p_character);
	
	printf("gebruik makend van enkel de pointer variabele\n");
	printf("de adres van integer = %p\n",p_integer);
	printf("de adres van komma_getal = %p\n",p_komma_getal);
	printf("de adres van character = %p\n\n",p_character);
	
	
	
	return 0;
	
}

