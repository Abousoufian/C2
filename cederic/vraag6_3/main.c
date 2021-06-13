#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 16

struct Node {
    char *word;
    struct Node* next;
};

void printList(struct Node* n);

void freeList(struct Node* n);

struct Node* push(struct Node *n,char element, char *pushword);

char *pop(struct Node **n, char element);

struct Node* sort(struct Node *n, char element);

int main()
{
    struct Node* head = NULL;
    char inputword[MAX] = {0};
    int keuze = 0;
    int element = 0;

    head = (struct Node*)malloc(sizeof (struct Node));

    printf("geef een woord in. ");
    gets(inputword);
    while (inputword[keuze] != '\0')
    {
        keuze ++;
    }
    head->word = (char*)calloc(sizeof (char),keuze);
    keuze = 0;
    strcpy(head->word,inputword);
    head->next = NULL;

    printList(head);

    do
    {
        printf("wat wil je doen?\n0 -> stoppen\n1 -> lijst printen\n2 -> data toevoegen\n3 -> data verwijderen\n4 -> sorteren\n");
        gets(inputword);
        keuze = atoi(inputword);
        switch (keuze)
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
                printf("op welke plaats wil je het woord toevoegen? -1 voor laatste, 0 voor eerste. ");
                do
                {
                    gets(inputword);
                    element = atoi(inputword);
                    //printf("%d\n",element);
                    if (element < -1)
                    {
                        printf("Plaatsen kunnen niet kleiner dan -1 zijn. ");
                    }
                }while (element < -1);
                printf("geef het woord in dat aan de lijst moet toegevoegd worden. ");
                gets(inputword);
                //printf("woord: %s element: %d\n",inputword, element);
                head = push(head, element, inputword);
                break;
            case 3:
                printf("op welke plaats wil je een woord verwijderen? -1 voor laatste, 0 voor eerste. ");
                do
                {
                    gets(inputword);
                    element = atoi(inputword);
                    {
                        printf("Plaatsen kunnen niet kleiner dan -1 zijn. ");
                    }
                }while (element < -1);
                strcpy(inputword,pop(&head, element));
                printf("%s\n",inputword);
                break;
            case 4:
                printf("hoe wil je sorteren? 0 voor van A naar Z en 1 voor van Z naar A. ");
                do
                {
                    gets(inputword);
                    element = atoi(inputword);
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
        printf("%s\n", n->word);
        n = n->next;
    }
}

void freeList(struct Node* n)
{
    struct Node* next = NULL;

    while (n != NULL)
    {
        next = n->next;
        free(n->word);
        free(n);
        n = next;
    }
}

struct Node* push(struct Node *n,char element, char *pushword)
{
    struct Node* head = n;
    struct Node* next = n->next;
    int counter = 0;

    while (pushword[counter] != '\0')
    {
        counter ++;
    }
    printf("%d\n",counter);

    if (element == 0)
    {
        printf("head \n");
        n = (struct Node*)malloc(sizeof (struct Node));
        n->word = (char*)calloc(sizeof (char), counter);
        strcpy(n->word,pushword);
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
            n->word = (char*)calloc(sizeof (char), counter);
            strcpy(n->word,pushword);
            n->next = next;
    }

    return head;
}

char *pop(struct Node **n, char element)
{
    struct Node* head = *n;
    struct Node* index = *n;
    struct Node* indexNext = index->next;
    char word[MAX] = {0};
    char *pointer = NULL;

    if(element == 0)
    {
        strcpy(word,head->word);
        index = index->next;
        free(head->word);
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
        strcpy(word,indexNext->word);
        index->next = indexNext->next;
        free(indexNext->word);
        free(indexNext);
    }



    *n = head;
    pointer = word;
    return pointer;
}

struct Node* sort(struct Node *n, char element)
{
    struct Node *head = n;
    struct Node *next  = n->next;
    struct Node *previous = NULL;
    int counter = 0;
    int exit = FALSE;

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
            for(int k = 0; k<MAX && exit == FALSE;k++)
            {
                exit = TRUE;
                if(n->word[k] > next->word[k] && element == 0)
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
                else if(n->word[k] < next->word[k] && element == 1)
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
                else if(n->word[k] == next->word[k])
                {
                    exit = FALSE;
                }
            }
            exit = FALSE;
            //printf("%d ",n->word);
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

