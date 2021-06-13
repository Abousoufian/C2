#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\examen\\COVID19.csv"
#define BESTAND2 "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\examen\\test.csv"


struct node{
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
	struct node *next;
}*head;



void create(char ar[9][300]);
void print();
void makeArray(char lijn[300],char ar[11][300]);
void search(char code[5]);

int main(int argc,char *argv[])
{
    FILE *fp = NULL;		
	
	
	
	int filter = atoi(argv[1]);
	printf("filter is %d\n",filter);
	
	
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
	
	//search(code);
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
	
	strcpy(temp->date,ar[0]);
	strcpy(temp->province,ar[1]);
	strcpy(temp->region,ar[2]);
	strcpy(temp->reporting_hospitals,ar[3]);
	strcpy(temp->total_patients,ar[4]);
	strcpy(temp->total_ICU,ar[5]);
	strcpy(temp->total_respitory,ar[6]);
	strcpy(temp->total_ECMO,ar[7]);
	strcpy(temp->new_intakes,ar[8]);
	strcpy(temp->discharges,ar[9]);
	strcpy(temp->trend,ar[10]);

	
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
        printf("|%s->%s->%s->%s->%s->|--\n",temp->date,temp->province,temp->region,temp->reporting_hospitals,temp->total_patients);
        temp=temp->next;
		if(end == 2){
			break;
		}
		end++;
    }
}

void makeArray(char lijn[300],char ar[11][300]){
	char *token = NULL;
	char dil[2] = ";";
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
		//if(strcmp(temp->ncic_code,code) == 0){
			//printf("|%s->%s->%s->%s->%s->%s->%s->%s->%s|--\n",temp->dateTime,temp->address,temp->district,temp->beat,temp->grid,temp->crimedescr,temp->ncic_code,temp->latitude,temp->longitude);
			fputs(temp->date,nieuw);
			fputs(",",nieuw);
			fputs(temp->province,nieuw);
			fputs(",",nieuw);
			fputs(temp->region,nieuw);
			fputs(",",nieuw);
			fputs(temp->trend,nieuw);
			fputc('\n',nieuw);
		//}

		temp=temp->next;
	}
	
	
	
}


