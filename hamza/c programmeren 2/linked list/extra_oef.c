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
	fseek(fp, 0L, SEEK_END);// zet de programma naar einde
	long int rsult = ftell(fp);
	printf("de groote is %d\n",rsult);
	rewind(fp);
	
	object *mem = (object*) malloc(10 * sizeof(object));
	char singleLine[rsult];

	while(!feof(fp)){
		fgets(singleLine, rsult, fp);
		
		token = strtok(singleLine, dil);													
		
		while(token != NULL){													
			//printf("%s\n",token);															
			//printf("de waarde van count is %d\n",count);
			
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
			
			
			count++;//telt de kolommen van de file
			if(count == 4){
				count = 0;
				
			}
			
			token = strtok(NULL, dil);
		}
		i++;
	}

	for(int y = 0; y != i; y++)
	{
		printf("%s\n",mem[y].first);
		printf("%s\n",mem[y].second);
		printf("%s\n",mem[y].third);
		printf("%s\n",mem[y].fourth);
	}
	

	fclose(fp);
	free(mem);
	return 0;
}
