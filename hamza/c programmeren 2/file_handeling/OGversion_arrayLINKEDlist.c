#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\idunno.txt"

struct node{
    char gerecht[20];
	char stad[20];
    struct node *next;
}*head[5];



void create(int count);
void print(int count);

int main()
{
    FILE *fp = NULL;		
	
	char *token = NULL;
	char dil[2] = "-";
	int count = 0;	
	
	
	fp = fopen(BESTAND, "r");
	
	if (fp == NULL) {
        printf("Error while opening file.\n");
        exit(EXIT_FAILURE);
    }
	
	
	
	
	
	for(int x = 0; x < 1; x++){
		printf("\ndit is een nieuwe element\n");
		create(x);
	}
	
	
	for(int b = 0; b < 3; b++){
		print(b);
	}
		

	fclose(fp);
	
	
    return 0;
}
void create(int count)
{ 
	struct node *temp;
	char line[128];
	char line2[128];
	
	for(int a = 0; a < 2; a++){
		
		printf("geef gerecht:");
		gets(line);
		printf("\n");
		printf("geef stad:");
		gets(line2);
		printf("\n");
		
		if(head[count]==NULL)		
		{
			temp=(struct node*)malloc(sizeof(struct node));	
			strcpy(temp->gerecht,line);
			strcpy(temp->stad,line2);
			temp->next=NULL;
			head[count]=temp;
		}
		else	
		{
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp=temp->next;
			strcpy(temp->gerecht,line);
			strcpy(temp->stad,line2);
			temp->next=NULL;
		}
	}
   
}


void print(int count)			//functie om de array uit te printen
{
    struct node *temp;
    temp=head[count];			//selecteerd welke linked list
    while(temp!=NULL)
    {
        printf("\ngerecht:%s->",temp->gerecht);
		printf("\nstad:%s->",temp->stad);		//hopt ge door de linked list
        temp=temp->next;
    }
}




