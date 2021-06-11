#include <stdio.h>
int main(void)
{
	int i = 10;
	int *p = &i;
	p[0] = 50;
	printf("%d\n", i+p[0]);
	return 0;
}

/*
	lijn 4: declaren van i met waarde 10
	lijn 5: pointer wordt aangemaakt die wijst naar i, dus locatie ervan
	lijn 6: "p[0]=50;" is het zelfde als je *p=50;" zou schrijven.
			Omdat i geen array is dien je 0 in te vullen, anders a je een foutmelding 
			krijgen.
	lijn 7: i is door lijn 6 50 geworden en p[0] wijst naar i dus ook 50, 50+50=100
*/