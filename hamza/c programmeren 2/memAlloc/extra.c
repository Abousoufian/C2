#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void memalloc()
{
	int* ptr = (int*)malloc(5 * sizeof(int));//malloc stuurt een void pointer terug die ge moet typecasten naar een type pointer
	
	printf("adres van de malloc %p\n",&ptr);
	
	for(int i = 0; i < 5; i++)
	{
		ptr[i] = 57+i;
	}
	
	for(int i = 0; i < 5; i++)
	{
		printf("de waarde: %d\t en het adres:%p\n",ptr[i], &ptr[i]);
	}
}



int main()
{
	memalloc();
	
	
	return 0;
}

