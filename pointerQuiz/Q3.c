#include <stdio.h>
int main(void)
{
	double gs_1=0;
	double *ptr=&gs_1;
	
	printf("Voer een getal in:");
	scanf("%lf", ptr);
	printf("Waarde in *ptr: %.2f\n", *ptr);
	return 0;
}
/*
	lijn 4: variabale aangemaakt van het type double
	lijn 5 pointer "double *ptr" aangemaakt die wijst naar de variable "gs_1"
	lijn 7: print functie
	lijn 8: neemt de waarde die door de gebruiker is ingetypt en gaat deze opslaan
			op de lacatie waarde die in "ptr" zit, omdat deze verwijst naar "gs_1"
			krijgt "gs_1" nu de waarde die de gebruiker heeft in ngetypt.
	lijn 9: print nu de waarde naar waar deze pointer naar toe verwijst.
			"ptr" verwijst naar "gs_1" en in "gs_1" zit de waarde in die de gebruiker heeft ingetypt
*/