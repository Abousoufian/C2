#include <stdio.h>

void setRange(int *ptrs_LR, int *ptrs_UR)
{
	printf("Geef de lower range in: ");
	scanf("%d", ptrs_LR);
	
	printf("Geef de upper range in: ");
	scanf("%d", ptrs_UR);
}

void productEvenNumb(int *ptrs_i, int *ptrs_multi)
{
	*ptrs_multi*=*ptrs_i;
}


int main()
{
	int low_Range=0;
	int upper_Range=0;
	int multi=1;
	
	setRange(&low_Range, &upper_Range);	
	
	for(int i= low_Range; i<=upper_Range; i++)
	{
		if(i%2==0)
		{
			productEvenNumb(&i, &multi);
		}
		else
		{
			//doet niets
		}
	}
	
	printf("Product van alle even getallen tussen %d en %d is %d", low_Range, upper_Range, multi);
	return 0;
}
