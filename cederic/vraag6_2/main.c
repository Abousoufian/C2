#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct Node {
    int number;
    struct Node* next;
};

void printList(struct Node* n);

void freeList(struct Node* n);

struct Node* push(struct Node *n,char element, int pushNumber);

int pop(struct Node **n, char element);

struct Node* sort(struct Node *n, char element);

int main()
{
    struct Node* head = NULL;
    int inputNumber = 0;
    int element = 0;

    head = (struct Node*)malloc(sizeof (struct Node));

    printf("geef een getal in. ");
    scanf(" %d",&inputNumber);

    head->number = inputNumber;
    head->next = NULL;

    printList(head);

    do
    {
        printf("wat wil je doen?\n0 -> stoppen\n1 -> lijst printen\n2 -> data toevoegen\n3 -> data verwijderen\n4 -> sorteren\n");
        scanf(" %d",&inputNumber);
        switch (inputNumber)
        {
            case 0:
                printList(head);
                freeList(head);
                exit(EXIT_SUCCESS);
                break;
            case 1:
                printList(head);
                break;
            case 2:
                printf("op welke plaats wil je het getal toevoegen? -1 voor laatste, 0 voor eerste. ");
                do
                {
                    scanf(" %d", &element);
                    if (element < -1)
                    {
                        printf("Plaatsen kunnen niet kleiner dan -1 zijn. ");
                    }
                }while (element < -1);
                printf("geef het getal in dat aan de lijst moet toegevoegd worden. ");
                scanf(" %d",&inputNumber);
                head = push(head, element, inputNumber);
                break;
            case 3:
                printf("op welke plaats wil je een getal verwijderen? -1 voor laatste, 0 voor eerste. ");
                do
                {
                    scanf(" %d", &element);
                    if (element < -1)
                    {
                        printf("Plaatsen kunnen niet kleiner dan -1 zijn. ");
                    }
                }while (element < -1);
                inputNumber = pop(&head, element);
                printf("%d\n",inputNumber);
                break;
            case 4:
                printf("hoe wil je sorteren? 0 voor van klein naar groot en 1 voor van groot naar klein. ");
                do
                {
                    scanf(" %d", &element);
                    if (element != 0 && element != 1)
                    {
                        printf("de parameter kan niet anders zijn dan 1 of 0. ");
                    }
                }while (element != 0 && element != 1);
                head = sort(head, element);
                break;
            default:
                printf("Er is geen juist comando ingegeven");
                break;

        }

    }while(1);






}

void printList(struct Node* n)
{
    system("cls");
    printf("De lijst\n");
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

struct Node* push(struct Node *n,char element, int pushNumber)
{
    struct Node* head = n;
    struct Node* next = n->next;

    if (element == 0)
    {
        n = (struct Node*)malloc(sizeof (struct Node));
        n->number = pushNumber;
        n->next = head;
        head = n;
    }
    else
    {
        if(element == -1)
        {
            while (n->next != NULL)
            {
                n = n->next;
                next = n->next;
            }
        }
        else
        {
            for (int i = 0; i<element-1 && n->next != NULL; i++)
            {
                n = n->next;
                next = n->next;
            }
        }

            n->next = (struct Node*)malloc(sizeof (struct Node));
            n = n->next;
            n->number = pushNumber;
            n->next = next;
    }

    return head;
}

int pop(struct Node **n, char element)
{
    struct Node* head = *n;
    struct Node* index = *n;
    struct Node* indexNext = index->next;
    int number = 0;

    if(element == 0)
    {
        number = head->number;
        index = index->next;
        free(head);
        head = index;
    }
    else
    {
        if(element == -1)
        {
            while(indexNext->next != NULL)
            {
                index = index->next;
                indexNext = index->next;
            }
        }
        else
        {
            for (int i = 0; i<element-1 && indexNext->next != NULL; i++)
            {
                index = index->next;
                indexNext = index->next;
            }
        }
        number = indexNext->number;
        index->next = indexNext->next;
        free(indexNext);
    }



    *n = head;
    return number;
}

struct Node* sort(struct Node *n, char element)
{
    struct Node *head = n;
    struct Node *next  = n->next;
    struct Node *previous = NULL;
    int counter = 0;

    while(n != NULL)
    {
        counter ++;
        n = n->next;
    }
    n = head;

    counter --;
    //printf("%d ",counter);

    for(int i = 0; i<counter; i++)
    {
        for(int j = 0; j<counter; j++)
        {
            //printf("%d ",j);
            if(n->number > next->number && element == 0)
            {

                if(previous == NULL)
                {
                    n->next = next->next;
                    next->next = n;
                    head = next;
                }
                else
                {
                    previous->next = next;
                    n->next = next->next;
                    next->next = n;
                }
                n = next;


            }
            else if(n->number < next->number && element == 1)
            {
                if(previous == NULL)
                {
                    n->next = next->next;
                    next->next = n;
                    head = next;
                }
                else
                {
                    previous->next = next;
                    n->next = next->next;
                    next->next = n;
                }
                n = next;

            }
            //printf("%d ",n->number);
            previous = n;
            n = previous->next;
            next = n->next;
        }
        if(i != counter-1)
        {
            n = head;
            next = n->next;
            previous = NULL;
        }
    }
    n->next = NULL;
    //printf("\n");
    return head;
}

