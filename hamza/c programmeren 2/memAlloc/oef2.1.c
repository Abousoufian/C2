#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//deze is met memalloc
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




	
	
	
	printf("hoeveel studenten wilt u registreren\n");
	gets(input);
	aantal = atoi(input);
	
	student *dynamicStudent = (student*) malloc(aantal * sizeof(student));
	
	for(int i = 0; i < aantal; i++)
	{
		printf("vul de details van student %d\n",i);
		
		printf("naam: ");
		gets(naam);

		strcpy(dynamicStudent[i].name,naam);
		
		printf("\nstudenten nummer: ");
		gets(input);
		studentennummer = atoi(input);

		dynamicStudent[i].studentnumber = studentennummer;
		
		printf("\npercentage: ");
		gets(input);
		percent = atof(input);
	;
		dynamicStudent[i].percentage = percent;
		
		printf("\n");
	}
	
	
	
	printf("de naam van student 1: %s\n",dynamicStudent[1].name); 
	
	free(dynamicStudent);//geheugen terug vrij geven


	
	return 0;
}

