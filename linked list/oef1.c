#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int getal;
    struct Node *next;
};
typedef struct Node node;



int main()
{
    char doorgaan = ' ';
    printf("continue?\n");
    doorgaan = getch();
    node *head = NULL;
    node *temp = NULL;
    int number = 0;
	char input = ' ';
    while (doorgaan == 'y')
    {
        temp = head;
        printf("enter number?\n");
        scanf(" %d", &number);
        while (temp != NULL && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
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
        printf("AGAIN?\n");
        doorgaan = getch();
		printf("you want to pop node?\n");
		input = getch();
		if(input == 'y')
		{
			temp = head;
			if (temp)
			{
				head = temp->next;

			}

		}



    }
    temp = head;
    printf("Here is the list?\n");
    printf("head is %d\n",head);
    while (temp != NULL)
    {
        printf("%d \n", temp->getal);
        temp = temp->next;
    }
    printf("head is %d",temp->getal);
    if(head < temp->next){
        printf("head is kleiner %d\n",head);
    }



	return 0;
}
