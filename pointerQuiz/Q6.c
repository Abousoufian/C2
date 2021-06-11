#include <stdio.h>
int main(void)
{
	int *ptr1;
	int	*ptr2; 
	int *ptr3;
	int i = 10;
	int j = 20;
	int k = 30;
	
	ptr1 = &i;          							//verwijst naar i
	i = 100;										// i krijgt waarde 100
	ptr2 = &j;										//verwijst naar j
	j = *ptr2 + *ptr1;								//j=20+100  j=120
	ptr3 = &k;										// verwijst naar k
	k = *ptr3 + *ptr2;								//k=30+120  k=150
	printf("%d %d %d\n", *ptr1, *ptr2, *ptr3);		// 100 120 150
	return 0;
}
