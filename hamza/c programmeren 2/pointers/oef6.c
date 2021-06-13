#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
//EIGENLIJK OEF 6

int order(int *smaller, int *bigger);

int main(){
	
	int lijst[] = {17, 12, 13, 9, 5, 1, 0, 7, 8, 16, 19}; 
	int lengte = 11;
	
	for(int i = 0; i < lengte - 1; i++)
	{
		for(int j = 0; j < lengte - i - 1; j++)
		{
			if(lijst[j] > lijst[j+1])
			{
				order(&lijst[j], &lijst[j+1]);
			}
		}			
	}
	for(int i = 0; i < lengte; i++)
	{
		printf("%d\n",lijst[i]);
	}
	
	
	return 0;
	
}

int order(int *smaller, int *bigger)
{
	
	if(*smaller == *bigger)
	{
		return FALSE;
	}
	else
	{
		if(*bigger < *smaller)
		{
			int temp = *smaller;
			*smaller = *bigger;
			*bigger = temp;
		}
		return TRUE;
	}
}
