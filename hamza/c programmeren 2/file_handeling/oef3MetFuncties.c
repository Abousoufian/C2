
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FGETS VOOR TEXTFILES GEBRUIKEN
#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\SacramentocrimeJanuary2006.txt"
#define NIEUW "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\wapenbezit.txt"

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

}object;

void parsing(FILE a){
	char singleLine[500];
	char dil[2] = ",";
	int count = 0;
	int i = 0;

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


			count++;//telt de kolommen van de file
			// if(count == 8){
				// count = 0;

			// }

			token = strtok(NULL, dil);
		}
		i++;
		count = 0;

	}
}



int main(){
	FILE *fp = NULL;
	FILE *nieuw = NULL;

	fp = fopen(BESTAND , "r");
	if(fp == NULL)
	{
		printf("cant open file\n");
		exit(EXIT_FAILURE);
		printf("program is closed\n");
		return 1;
	}

	fseek(fp, 0L, SEEK_END);// zet de programma naar einde
	rewind(fp);

	object *mem = (object*) malloc(10000 * sizeof(object));

	char singleLine[500];

	fgets(singleLine, 500, fp);//ignore header

    parsing(fp);
    printf("%s\n",mem[222].crimedescr);



	fclose(nieuw);
	fclose(fp);
	free(mem);
	return 0;
}
