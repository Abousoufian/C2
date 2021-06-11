#include <stdio.h>
int main(void)
{
	int i = 0;
	*ptr = &i;
	*ptr = *ptr ? 10 : 20;
	printf("%d\n", i);
	return 0;
}

/*
	if(*ptr)						//*ptr heeft waarde nul dus altijd false
	{
		printf("%d", 10);
	}
	else
	{
		printf("%d", 20);
	}
*/
