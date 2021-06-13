#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char *string;					//hier gaat de data in
    struct list *next;				//das gwn de next pointer
};

typedef struct list LIST;

#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\idunno.txt"

int main(void) {
    FILE *fp = NULL;				//de file pointer
	char line[128];					//neemt 1 lijn van de file op (dezelfde als singleLine)
    LIST *current, *head;	
	int i = 0;
	
	char *token = NULL;
	char dil[2] = "-";
	char test[50];

    head = current = NULL;			//initialiseren op NULL
    fp = fopen(BESTAND, "r");
	
	if (fp == NULL) {
        printf("Error while opening file.\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line, sizeof(line), fp)){		//als einde file er is wordt nul pointer terug gestuurd en while eindigt
        LIST *node = malloc(sizeof(LIST));		// node wortd gealloceerd
        node->string[i] = strdup(line);//note : strdup is not standard function -duplicate string- en verwijst naar een NULL pointer (zelfde als strcpy, denk ik)
        node->next =NULL;

        if(head == NULL){
            current = head = node;
        } else {
            current = current->next = node;
        }
		i++;
    }
    fclose(fp);
    //test print
    for(current = head; current ; current=current->next){
        printf("%s", current->string);
    }
   //yup kan 2 keer printe
	
	for(current = head; current ; current=current->next){
        token = strtok(test,dil);
		while(token != NULL){
			
		}
    }
	
	
    return 0;
}





