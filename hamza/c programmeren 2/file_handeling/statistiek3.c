#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FGETS VOOR TEXTFILES GEBRUIKEN
#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\wapenbezit.txt"
#define NIEUW "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\uren.txt"

typedef struct
{
    char dateTime[15];
	char address[30];
	char district[2];
	char beat[3];
	char grid[5];
	char crimedescr[50];
	char ncic_code[5];
	char latitude[15];
	char longitude[15];
	char time[10];
	char date[10];
}object;


int main()
{
	FILE *fp = NULL;
	FILE *nieuw = NULL;
	char *token = NULL;
	char *token2 = NULL;
	char dil[2] = ",";
	char dilTIME[2] = "\0";
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
	// printf("%d",rsult);
	rewind(fp);

	object *mem = (object*) malloc(10000 * sizeof(object));

	char singleLine[500];

	fgets(singleLine, 500, fp);//ignore header

	while(!feof(fp)){
		fgets(singleLine, 500, fp);


		token = strtok(singleLine, dil);

		while(token != NULL){
			// printf("%s\n",token);
			// printf("de waarde van count is %d\n",count);

			switch(count){
				case 0:
					strcpy(mem[i].dateTime,token);
					break;

				case 1:
					strcpy(mem[i].address,token);
					break;

				case 2:
					strcpy(mem[i].district,token);
					break;

				case 3:
					strcpy(mem[i].beat,token);
					break;

				case 4:
					strcpy(mem[i].grid,token);
					break;

				case 5:
					strcpy(mem[i].crimedescr,token);
					break;

				case 6:
					strcpy(mem[i].ncic_code,token);
					break;

				case 7:
					strcpy(mem[i].latitude,token);
					break;

				case 8:
					strcpy(mem[i].longitude,token);
					break;
			}


			count++;

			token = strtok(NULL, dil);
		}
		i++;
		count = 0;

	}
	count = 0;
	printf("%s\n",mem[2].dateTime);
    printf("%s\n",mem[2].ncic_code);
    printf("%s\n",mem[2].latitude);
	
	
	for(int a = 0; a < i; a++){
		token2 = strtok(mem[a].dateTime, dilTIME);
		while(token != NULL){
			switch(count){
				case 0: 
					strcpy(mem[a].date,token2);
					break;
				case 1:
					strcpy(mem[a].time,token2);
					break;
			}
			
		}
	}
	
	printf("%s\n",mem[1].time);
	
	
	nieuw = fopen(NIEUW,"a");
	if(nieuw == NULL)
	{
		printf("cant open file\n");
		exit(EXIT_FAILURE);
		printf("program is closed\n");
		return 1;
	}
	else{
		fputs("wafels zijn lekker\n",nieuw);//backslash n werkt
		fputs("zeker die met kokosnoot",nieuw);
	}
    fclose(nieuw);
	fclose(fp);
	free(mem);
	
	return 0;
}
