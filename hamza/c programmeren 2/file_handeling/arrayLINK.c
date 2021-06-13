#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\SacramentocrimeJanuary2006.txt"
#define BESTAND2 "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\new.txt"


struct node{
    char dateTime[15];
    char address[30];
	char district[2];
	char beat[3];
	char grid[5];
	char crimedescr[50];
	char ncic_code[5];
	char latitude[15];
	char longitude[15];
    struct node *next;
}*head;



void create(char ar[9][300]);
void print();
void makeArray(char lijn[300],char ar[9][300]);
void search(char code[5]);

int main()
{
    FILE *fp = NULL;		
	
	
	
	char lijn[300];
	char ar[9][300];
	int test = 0;
	char code[5] = "5212";
	
	fp = fopen(BESTAND, "r");
	
	if (fp == NULL) {
        printf("Error while opening file.\n");
        exit(EXIT_FAILURE);
    }
	fgets(lijn,300,fp);
	while(!feof(fp))
	{

		fgets(lijn,300,fp);
		makeArray(lijn,ar);
		create(ar);
		test++;
	}
	
	print();
	
	search(code);
	fclose(fp);
	
    return 0;
}


void create(char ar[9][300])
{ 
	struct node *temp = (struct node*)malloc(sizeof(struct node));

	
	if (temp == NULL){
		printf("temp was NULL.\n");
        exit(EXIT_FAILURE);
	}
	
	strcpy(temp->dateTime,ar[0]);
	strcpy(temp->address,ar[1]);
	strcpy(temp->district,ar[2]);
	strcpy(temp->beat,ar[3]);
	strcpy(temp->grid,ar[4]);
	strcpy(temp->crimedescr,ar[5]);
	strcpy(temp->ncic_code,ar[6]);
	strcpy(temp->latitude,ar[7]);
	strcpy(temp->longitude,ar[8]);
	
	temp->next = head;
	head = temp;
	
}


void print()			
{
    struct node *temp;
    temp=head;	
	int end = 0;
    while(temp!=NULL)
    {
        printf("|%s->%s->%s->%s->%s->%s->%s->%s->%s|--\n",temp->dateTime,temp->address,temp->district,temp->beat,temp->grid,temp->crimedescr,temp->ncic_code,temp->latitude,temp->longitude);
        temp=temp->next;
		if(end == 2){
			break;
		}
		end++;
    }
}

void makeArray(char lijn[300],char ar[9][300]){
	char *token = NULL;
	char dil[2] = ",";
	int count = 0;
	
	token = strtok(lijn,dil);
	while(token != NULL){
		strcpy(ar[count],token);
		count++;
		token = strtok(NULL, dil);
	}	
}

void search(char code[5]){
	FILE *nieuw = NULL;
	struct node *temp;
	int locatie[150];
	int a,count = 0;
	temp = head;
	
	nieuw = fopen(BESTAND2,"a");
	
	while(temp != NULL){
		if(strcmp(temp->ncic_code,code) == 0){
			//printf("|%s->%s->%s->%s->%s->%s->%s->%s->%s|--\n",temp->dateTime,temp->address,temp->district,temp->beat,temp->grid,temp->crimedescr,temp->ncic_code,temp->latitude,temp->longitude);
			fputs(temp->dateTime,nieuw);
			fputs(",",nieuw);
			fputs(temp->address,nieuw);
			fputs(",",nieuw);
			fputs(temp->district,nieuw);
			fputs(",",nieuw);
			fputs(temp->beat,nieuw);
			fputs(",",nieuw);
			fputs(temp->grid,nieuw);
			fputs(",",nieuw);
			fputs(temp->crimedescr,nieuw);
			fputs(",",nieuw);
			fputs(temp->ncic_code,nieuw);
			fputs(",",nieuw);
			fputs(temp->latitude,nieuw);
			fputs(",",nieuw);
			fputs(temp->longitude,nieuw);
		}

		temp=temp->next;
	}
	
	
	
}


