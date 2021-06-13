#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//deze is zonder memalloc
typedef struct
{
	char name[30];
	int studentnumber;
	float percentage;
}student;

int main()
{
	int aantal = 0;	
	char naam[30];
	int studentennummer = 0;
	float percent = 0;
	char input[10];
	student list;
	student arr_student[5];
	
	printf("hoeveel studenten wilt u registreren\n");
	gets(input);
	aantal = atoi(input);
	
	student *dynamicStudent = (student*) malloc(aantal * sizeof(student));
	
	for(int i = 0; i < aantal; i++)
	{
		printf("vul de details van student %d\n",i);
		
		printf("naam: ");
		gets(naam);
		strcpy(arr_student[i].name, naam);
		
		
		printf("\nstudenten nummer: ");
		gets(input);
		studentennummer = atoi(input);
		arr_student[i].studentnumber = studentennummer;
		/
		
		printf("\npercentage: ");
		gets(input);
		percent = atof(input);
		arr_student[i].percentage = percent;
		
		
		printf("\n");
	}
	
	
	
	
	
	printf("de naam van student 1: %s\n",arr_student[1].name);

	
	
	return 0;
}

