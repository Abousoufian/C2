#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FGETS VOOR TEXTFILES GEBRUIKEN
#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\test.txt"

typedef struct 
{
    char first[20];
	char second[20];
	char third[20];
	char fourth[20];

}object;


int main()
{
	FILE *fp = NULL;
	char singleLine[150];
	char *token = NULL;
	char dil[2] = ";";
	int count = 0;
	int i = 0;
	fp = fopen(BESTAND , "r");
	if(fp == NULL)
	{
		printf("cant open file\n");
		exit(EXIT_FAILURE);
		printf("program is closed\n");
		return 1;
	}

	//object *mem = (object*) malloc(10 * sizeof(object));


	while(!feof(fp)){
		fgets(singleLine, 150, fp);
	}
		
	while(token != NULL){													
		//printf("%s\n",token);															
		//printf("de waarde van count is %d\n",count);
		token = strtok(singleLine, dil);
		switch(count){
			case 0: 
				strcpy(mem[i].first,token); 
				break;
				
			case 1: 
				strcpy(mem[i].second,token);
				break;
				
			case 2: 
				strcpy(mem[i].third,token);
				break;
			
			case 3:
				strcpy(mem[i].fourth,token);
				break;
		}
		
		i++;
		count++;//telt de kolommen van de file
		if(count == 4){
			count = 0;
		}
		
		token = strtok(NULL, dil);
	}
	

	// for(int y = 0; y != 2; y++)
	// {
		// printf("%s\n",mem[y].first);
		// printf("%s\n",mem[y].second);
		// printf("%s\n",mem[y].third);
		// printf("%s\n",mem[y].fourth);
	// }
	

	fclose(fp);
	//free(mem);
	return 0;
}
