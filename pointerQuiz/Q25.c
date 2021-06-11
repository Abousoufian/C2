#include <stdio.h>
int main(void)
{
	int k = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int m=0;
	int a[3];
	
	int *p[] = {&k, &b, &c, &d};
	for(m = 0; m < 3; m++)
	{
		a[*p[m]] = **(p+m+1);
	}
	return 0;
}
