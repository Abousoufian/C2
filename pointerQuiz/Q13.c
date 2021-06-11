#include <stdio.h>

void scanGrades(double *ptr_T1, double *ptr_T2, double *ptr_T3)
{
	printf("Voer de punten in van de eerste test: ");
	scanf("%lf", ptr_T1);
	
	printf("Voer de punten in van de tweede test: ");
	scanf("%lf", ptr_T2);
	
	printf("Voer de punten in van de derde test: ");
	scanf("%lf", ptr_T3);
}

void descendingOrder(double *ptr_T1, double *ptr_T2, double *ptr_T3)
{
	double arr[4]={*ptr_T1,*ptr_T2,*ptr_T3};
	
	for(int i=0; i<3; i++)
	{
		for(int j=i+1; j<3; j++)
		{
			if(arr[i] < arr[j])
			{
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
			else
			{
				//doet niets
			}
		}
	}
	
	for(int i=0; i<3; i++)
	{
		printf("%.2lf\n", arr[i]);
	}
	
}

void average(double *ptr_T1, double *ptr_T2, double *ptr_T3, double *ptr_average)
{
	*ptr_average=(*ptr_T1+*ptr_T2+*ptr_T3)/3;
	printf("Het gemiddelde is %.2lf", *ptr_average);
}

int main()
{
	double test1=0;
	double test2=0;
	double test3=0;
	double gemiddelde=0;
	
	scanGrades(&test1, &test2, &test3);	
	
	if(test1>=5 && test2>=5 && test3>=5)
	{
		descendingOrder(&test1, &test2, &test3);
	}
	else
	{
		average(&test1, &test2, &test3, &gemiddelde);
	}
	return 0;
}
