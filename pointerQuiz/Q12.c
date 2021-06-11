#include <stdio.h>
int main(void)
{
	int *ptr; 
	int i = 0;
	for(ptr=&i; *ptr < 5; i++)
	{
		(*ptr)++;
		++*ptr;
		printf("%d ", i);
	}
	return 0;
}

// 2
// 5