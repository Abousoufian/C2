#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FGETS VOOR TEXTFILES GEBRUIKEN
#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\test.txt"

typedef struct 
{
    char first[8];
	char second[8];
	char third[8];
	char fourth[8];

}object;


int main()
{
	FILE *fp = NULL;
	char singleLine[150];
	char *token = NULL;
	char dil[2] = ";";


	fp = fopen(BESTAND , "r");
	if(fp == NULL)
	{
		printf("cant open file\n");
		exit(EXIT_FAILURE);
		printf("program is closed\n");
		return 1;
	}
	//de programma om te parsen
	
	while(!feof(fp)){						//dit zegt blijf lezen totdat ge de einde van de file bereikt hebt
		fgets(singleLine, 150, fp);			//leest lijn per lijn
		printf("%s",singleLine);			//steekt da in een string met de \n erin verwerkt
	
	
	printf("\n de gesplitste woorden:\n");
	token = strtok(singleLine, dil);
	
	while(token != NULL){
		printf("%s\n",token); 
		token = strtok(NULL, dil);
	}
	}
	fclose(fp);
	
	return 0;
}


