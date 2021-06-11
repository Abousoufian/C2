#include <stdio.h>
int main(void)
{
	int i;
	int *ptr1;
	int *ptr2;
	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	ptr1 = &arr[2];
	ptr2 = &arr[4];
	
	printf("%d\n", ptr1);
	printf("%d\n", ptr2);
	printf("%d\n", *ptr1);
	i = ptr2-ptr1;
	printf("%d\n", i);
	printf("%d\n", ptr1[2]);
	printf("%d\n", ptr1[4]);
	for(i = ptr2-ptr1; i < 5; i+=2)
		printf("%d\n", ptr1[i]);
	return 0;
}
