#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\SacramentocrimeJanuary2006.txt"
#define BESTAND2 "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\test.txt"

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
}*head[8000];		//dit heb ik beslist



void search(char zoek[5]);
void create(int count,char line[300]);
void print(int count);

int main()
{
    FILE *fp = NULL;		
	char lijn[300];
	int count = 0;
	
	fp = fopen(BESTAND, "r");
	
	if (fp == NULL) {
        printf("Error while opening file.\n");
        exit(EXIT_FAILURE);
    }
	
	fgets(lijn,300,fp);
	while(!feof(fp)){
		fgets(lijn,300,fp);
		//printf("de lijn is:%s\n",lijn);
		create(count,lijn);
		count++;
	}
	
	
	for(int b = 0; b <= 1; b++){
		print(b);
	}
	
	char zoek[5] = "2501";
	search(zoek);

	fclose(fp);
	
	
	
    return 0;
}
void create(int count,char line[300])	//creeert de nodes
{ 
	struct node *temp;
	char *token = NULL;
	char dil[2] = ",";
	int categorie = 0;
	
	token = strtok(line,dil);
	
	while(token != NULL){
		
		if(head[count]==NULL)		
		{
			temp=(struct node*)malloc(sizeof(struct node));	
			if(categorie == 0){
			strcpy(temp->dateTime,token);
			}
			temp->next=NULL;
			head[count]=temp;
		}
		else	
		{
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp=temp->next;
			if(categorie == 1){
				strcpy(temp->address,token);
			}
			else if(categorie == 2){
			strcpy(temp->district,token);
			}
			else if(categorie == 3){
				strcpy(temp->beat,token);
			}
			else if(categorie == 4){
				strcpy(temp->grid,token);
			}
			else if(categorie == 5){
				strcpy(temp->crimedescr,token);
			}
			else if(categorie == 6){
				strcpy(temp->ncic_code,token);
			}
			else if(categorie == 7){
				strcpy(temp->latitude,token);
			}
			else if(categorie == 8){
				strcpy(temp->longitude,token);
			}
			temp->next=NULL;
		}
		
		categorie++;
		token = strtok(NULL, dil);
	}
	
   
}


void print(int count)			//functie om de array uit te printen
{
    struct node *temp;
	int categorie = 0;
    temp=head[count];			
    while(temp!=NULL)
    {
		if(categorie == 0){
			printf("date&time: %s->\n",temp->dateTime);
		}
		else if(categorie == 1){
			printf("address: %s->\n",temp->address);
		}
		else if(categorie == 2){
			printf("district: %s->\n",temp->district);
		}
		else if(categorie == 3){
			printf("beat: %s->\n",temp->beat);
		}
		else if(categorie == 4){
			printf("grid: %s->\n",temp->grid);
		} 
		else if(categorie == 5){
			printf("crimedescription: %s->\n",temp->crimedescr);
		}
		else if(categorie == 6){
			printf("ncic code: %s->\n",temp->ncic_code);
		}
		else if(categorie == 7){
			printf("latitude: %s->\n",temp->latitude);
		}
		else if(categorie == 8){
			printf("longitude: %s->\n",temp->longitude);
		}
		
        temp=temp->next;
		categorie++;
    }
}

void search(char zoek[5])
{
	struct node *temp;
	int aantal = 0;
	FILE *nieuw = NULL;
	int locaties[50];
	int a = 0;
	
	nieuw = fopen(BESTAND2,"a");
	if(nieuw == NULL)
	{
		printf("cant open file\n");
		exit(EXIT_FAILURE);
	}
	
	for(int x = 0; x < 8000; x++){
		temp = head[x];
		while(temp != NULL){
			if(strcmp(zoek,temp->ncic_code) == 0){
				printf("hier is een: %s\n",temp->ncic_code);
				//aantal++;
				locaties[a] = x;
				a++;
				
			}
			temp = temp->next;
			
		}
	}
	
	a = 0;
	
	for(int x = 0; x < 21; x++){
		temp = head[locaties[x]];
		while(temp != NULL){
			switch(a){
				case 0:
					fputs(temp->dateTime,nieuw);	
					fputs(",",nieuw);
					break;
			
				case 1:
					fputs(temp->address,nieuw);	
					fputs(",",nieuw);
					break;
					
				case 2:
					fputs(temp->district,nieuw);	
					fputs(",",nieuw);
					break;
			
				case 3:
					fputs(temp->beat,nieuw);	
		 			fputs(",",nieuw);
					break;
					
				case 4:
					fputs(temp->grid,nieuw);	
					fputs(",",nieuw);
					break;
			
				case 5:
					fputs(temp->crimedescr,nieuw);	
					fputs(",",nieuw);
					break;
					
				case 6:
					fputs(temp->ncic_code,nieuw);	
					fputs(",",nieuw);
					break;
			
				case 7:
					fputs(temp->latitude,nieuw);	
					fputs(",",nieuw);
					break;	
					
				case 8:
					fputs(temp->longitude,nieuw);	
					fputs(",",nieuw);
					break;
			
			}
			temp = temp->next;
			a++;
		}
		a = 0;
		printf("de locaties %d\n",locaties[x]);
	}
	
	fclose(nieuw);
	//printf("het aantal keren dat %s is gevonden: %d\n",zoek,aantal);
}


