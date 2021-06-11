#include <stdio.h>
int main(void)
{
	int *ptr;
	int arr[5] = {20, 0, 0, 0, 0};
	for(ptr = arr+1; ptr < arr+4; ptr++)
	{
		*ptr = *(ptr-1) + *(ptr+1) + 1;
		printf("%d\n",*ptr);
		printf("%d\n",ptr);
	}
	
	for(int i=0; i<5; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
