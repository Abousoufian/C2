#include <stdio.h>

int main(void)
{
	float grade=0.0;	
	int sum=0;	
	float max=0.0;	
	
	scanGrades(&sum, &grade, &max);
	
	printf("%d\n", sum);
	printf("%.2lf\n", max);
}

