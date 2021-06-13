#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node* next;
};

void printList(struct Node* n);

void freeList(struct Node* n);

int main()
{
    struct Node* head = NULL;
    struct Node* taile = NULL;
    int placeholder = 0;

    head = (struct Node*)malloc(sizeof (struct Node));
    taile = head;

    printf("geef een getal in. ");
    scanf(" %d",&placeholder);

    head->number = placeholder;
    head->next = NULL;

    printList(head);

    do
    {
        printf("geef het volgende getal in. Geef -1 in om te stoppen. ");
        scanf(" %d",&placeholder);
        if (placeholder == -1)
        {
            printList(head);
        }
        else
        {
            taile->next = (struct Node*)malloc(sizeof (struct Node));
            taile = taile->next;
            taile->number = placeholder;
            taile->next = NULL;
            printList(head);
        }
    }while(placeholder != -1);






}

void printList(struct Node* n)
{
    while (n != NULL)
    {
        printf("%d\n", n->number);
        n = n->next;
    }
}

void freeList(struct Node* n)
{
    struct Node* next = NULL;

    while (n != NULL)
    {
        next = n->next;
        free(n);
        n = next;
    }
}
