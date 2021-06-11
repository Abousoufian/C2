#include <stdio.h>
int main(void)
{
	int *ptr1;
	int *ptr2;
	int i = 10;
	int j = 20;
	
	ptr1 = &i;	//10
	ptr2 = &j;	//20
	
	ptr2 = ptr1;	//10
	*ptr1 = *ptr1 + *ptr2;	//20
	*ptr2 *= 2;			//40
	printf("%d\n", *ptr1 + *ptr2);	//80
	return 0;
}

