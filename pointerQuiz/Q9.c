#include <stdio.h>
int main(void)
{
	int i=0;
	int *p=&i;
	
	while(*p<10)
	{
		(*p)++;
		printf("%d\n", *p);
	}
}
