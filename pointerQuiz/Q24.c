#include <stdio.h>
int main(void)
{
	int *p[3];
	int i=0;
	int num=0;
	
	for(i = 0; i < 3; i++)
	{
		printf("Enter number: ");
		scanf("%d", &num);
		p[i] = &num;
	}
	for(i = 0; i < 3; i++)
	{
		printf("Num: %d\n", *p[i]);	
	}
	return 0;
}
