#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//de bestands locaties moeten verander worden EN EXCEL weigert om de datums te printen maar in kladblok staan ze wel
#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\examen\\COVID19.csv"
#define BESTAND2 "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\examen\\minimum_aantal_Total_of_hospitalized_patients.csv"


typedef struct
{
    char date[15];
	char province[20];
	char region[20];
	char reporting_hospitals[5];
	char total_patients[10];
	char total_ICU[10];
	char total_respitory[10];
	char total_ECMO[10];
	char new_intakes[10];
	char discharges[10];
	char trend[10];
}object;


int main(int argc,char *argv[])
{
	FILE *fp = NULL;
	FILE *nieuw = NULL;
	char *token = NULL;
	char dil[2] = ";";
	int count = 0;
	int i = 0;
	int intakes = 0;
	int discharge = 0;
	int trent = 0;
	int waarde = 0;
	

	int filter = atoi(argv[1]);
	printf("filter is %d\n",filter);
	
	
	fp = fopen(BESTAND , "r");
	if(fp == NULL)
	{
		printf("cant open file\n");
		exit(EXIT_FAILURE);
	}



	object *mem = (object*) malloc(10000 * sizeof(object));

	char singleLine[500];

	fgets(singleLine, 500, fp);
	//file parsing gedeelte
	while(!feof(fp)){
		fgets(singleLine, 500, fp);


		token = strtok(singleLine, dil);

		while(token != NULL){


			switch(count){
				case 0:
					strcpy(mem[i].date,token);
					break;

				case 1:
					strcpy(mem[i].province,token);
					break;

				case 2:
					strcpy(mem[i].region,token);
					break;

				case 3:
					strcpy(mem[i].reporting_hospitals,token);
					break;

				case 4:
					strcpy(mem[i].total_patients,token);
					break;

				case 5:
					strcpy(mem[i].total_ICU,token);
					break;

				case 6:
					strcpy(mem[i].total_respitory,token);
					break;

				case 7:
					strcpy(mem[i].total_ECMO,token);
					break;

				case 8:
					strcpy(mem[i].new_intakes,token);
					break;
					
				case 9:
					strcpy(mem[i].discharges,token);
					break;
			}


			count++;

			token = strtok(NULL, dil);
		}
		i++;
		count = 0;

	}

	//nieuwe bestand openene/crieeeren
	nieuw = fopen(BESTAND2 , "a");
	if(nieuw == NULL)
	{
		printf("cant open file\n");
		exit(EXIT_FAILURE);
	}




	fputs("date;province;region;trend",nieuw);	//hoofdding invullen
	fputc('\n',nieuw);
	
	//de nieuwe file invullen
	char tussen[10];
	for(int a = 0; a < i; a++){
		waarde = atoi(mem[a].total_patients);
		if(waarde >= filter){
			intakes = atoi(mem[a].new_intakes);
			discharge = atoi(mem[a].discharges);
			trent = intakes - discharge;
			itoa(trent,tussen,10);		//deze functie zet een int om naar een array
			strcpy(mem[a].trend,tussen);

			fputs(mem[a].date,nieuw);
			fputs(";",nieuw);
			fputs(mem[a].province,nieuw);
			fputs(";",nieuw);
			fputs(mem[a].region,nieuw);
			fputs(";",nieuw);
			fputs(mem[a].trend,nieuw);
			fputc('\n',nieuw);
		}
	}
	
	
	int getallen[i];
	int n = 0;
	int swap = 0;
	
	//alle trends in een int array steken
	for(int a = 0; a < i; a++){
		getallen[a] = atoi(mem[a].trend);
		n++;
	}
	
	//bubble sorten
	for (int c = 0 ; c < n - 1; c++)
	{
		for (int d = 0 ; d < n - c - 1; d++)
		{
		  if (getallen[d] > getallen[d+1]) 
		  {
			swap = getallen[d];
			getallen[d] = getallen[d+1];
			getallen[d+1] = swap;
		  }
		}
	}
	
	//de laagste waarde zoeken in de struct en printen
	itoa(getallen[0],tussen,10);
	for(int a = 0; a < i; a++){
		if(strcmp(tussen,mem[a].trend) == 0){
			printf("op datum %s was de trend %s in de provintie %s",mem[a].date,mem[a].trend,mem[a].province);
		}
		
	}

	fclose(fp);
	fclose(nieuw);
	free(mem);
	return 0;
}

