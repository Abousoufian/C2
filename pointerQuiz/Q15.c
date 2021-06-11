#include <stdio.h>

void upperNumb(int *g1_ptr)
{
	do
	{
		printf("Geef het eerste getal in: ");
		scanf("%d", g1_ptr);
	}
	while(*g1_ptr>100);
}

void lowerNumb(int *g2_ptr, int *g1_ptr)
{
	do
	{
		printf("Geef het tweede getal in: ");
		scanf("%d", g2_ptr);
	}
	while(*g2_ptr>*g1_ptr);
}

int main()
{
	int getal1=0;    
	int getal2=0;    
	int sum=0;
	
	upperNumb(&getal1);
	lowerNumb(&getal2, &getal1);
	
	for(getal2+=1; getal2<getal1; getal2++)
	{
		sum+=getal2;
	}
	
	printf("%d", sum);
	
	return 0;
}

