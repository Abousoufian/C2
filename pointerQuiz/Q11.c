#include <stdio.h>

void highestGrade(float *p2_Grade, float *p3_Max)
{
	if(*p3_Max<*p2_Grade)
	{
		*p3_Max=*p2_Grade;
	}
	else
	{
		//doet niets
	}
}

void howManyBetween5_10(float *p2_Grade, int *p1_Sum)
{
	if(*p2_Grade!=-1)
		{
			if(*p2_Grade>=5 && *p2_Grade<=10)
			{
				(*p1_Sum)++;
			}
			else
			{
				//doet niets
			}
		}
		else
		{
			//doet niets
		}
}

int main(void)
{
	float grade=0.0;
	float *p2_Grade=&grade;
	
	int sum=0;	
	float max=0.0;	
	
	while(*p2_Grade!=-1)
	{
		printf("Vul de punten van de student in: ");
		scanf("%f", p2_Grade);
		
		highestGrade(&grade, &max);
		howManyBetween5_10(&grade, &sum);
	}
	
	printf("%d\n", sum);
	printf("%.2lf\n", max);
}

