#include <stdio.h>

void numbSwap(double *g1Ptr, double *g2Ptr)
{
	int temp=0;
	temp=*g1Ptr;
	*g1Ptr=*g2Ptr;
	*g2Ptr=temp;
}

void highestNumb(double *g1Ptr, double *g2Ptr, double *hghNumb)
{
	if(*g1Ptr<*g2Ptr)
	{
		*hghNumb=*g2Ptr;
	}
	else
	{
		*hghNumb=*g1Ptr;
	}
}

int main(void)
{
	double getal1=0;
	double getal2=0;
	double grootsteGtal=0;
	
	printf("Voer het eerste getal in: ");
	scanf("%lf", &getal1);
	
	printf("Voer het tweede getal in: ");
	scanf("%lf", &getal2);
	
	printf("geta11: %.2lf\n", getal1);
	printf("geta12: %.2lf\n", getal2);
	
	numbSwap(&getal1, &getal2);
	
	printf("geta11: %.2lf\n", getal1);
	printf("geta12: %.2lf\n", getal2);
	
	highestNumb(&getal1, &getal2, &grootsteGtal);
	printf("grootste getal is %.2lf\n", grootsteGtal);
	
	return 0;
}
