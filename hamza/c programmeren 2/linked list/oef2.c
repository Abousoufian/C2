#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    int getal;
    struct Node *next;
}node;



int main(){
    node *head = NULL;
    node *temp = NULL;
    char input = ' ';
    int number = 0;

    printf("wil je een node\n");
    input = getch();

    while(input = 'y'){
        temp = head;
        printf("vul een getal in\n");
        scanf("%d",&number);
        while(temp != NULL && temp->next != NULL){
            temp = temp->next;
        }

        if(temp == NULL){
            head = (node *)malloc(sizeof(node));
            head->getal = number;
            head->next = NULL;
        }

        else
        {
            temp->next = (node *)malloc(sizeof(node));
            temp->next->getal = number;
            temp->next->next = NULL;
        }

        printf("you want to pop node?\n");
        getch(input);

        if(input == 'y'){
            temp = head;
			if (temp)
			{
				head = temp->next;

			}
        }

    }
    temp = head;
    printf("Here is the list?");
    while (temp != NULL)
    {
        printf("%d \n", temp->getal);
        temp = temp->next;
    }




    return 0;
}
