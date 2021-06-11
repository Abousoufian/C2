#include <stdio.h>
#define SIZE 10


void scanGrades(int *arr_ptr)
{
	for(int i=0; i<10; i++)
	{
			printf("Vul de punten in van student %d in: ", i+1);
			scanf("%d", arr_ptr);
			arr_ptr +=1;	
	}
}

void scanMinGrade(int *minGrade, int *pos, int *arr_ptr)
{
	for(int i=0; i<10; i++)
	{
		if(*arr_ptr<*minGrade)
		{
			*minGrade=*arr_ptr;
			*pos=i;
			arr_ptr +=1;
		}
		else
		{
			arr_ptr +=1;
		}
	}
}

void scanMaxGrade(int *maxGrade, int *pos, int *arr_ptr)
{
	for(int i=0; i<10; i++)
	{
		if(*arr_ptr>*maxGrade)
		{
			*maxGrade=*arr_ptr;
			*pos=i;
			arr_ptr +=1;
		}
		else
		{
			arr_ptr +=1;
		}
	}
}


int main()
{
	int max_pos=0;
	int min_pos=0;
	int max=0;
	int min=10; 
	int arr[SIZE];

	scanGrades(arr);
	scanMinGrade(&min, &min_pos, arr);
	scanMaxGrade(&max, &max_pos, arr);
	printf("Het laagste cijfer bedraagt %d\n", min);
	printf("Het laagste cijfer bevindt zich op index %d van de array\n", min_pos);
	printf("Het hoogste cijfer bedraagt %d\n", max);
	printf("Het hoogste cijfer bevindt zich op index %d van de array\n", max_pos);
	
}
