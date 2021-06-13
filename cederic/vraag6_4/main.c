#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 16

typedef enum {
    Man,
    Vrouw,
    Onzijdig,
}geslacht;

struct Node {
    char *Voornaam;
    char *Achternaam;
    char leeftijd;
    float totaleScore;
    geslacht geslacht;
    struct Node* next;
};

void printList(struct Node* n);

void printStudent (struct Node* n, char *achternaam);

void freeList(struct Node* n);

struct Node* push(struct Node *n,char element);

char *pop(struct Node **n, char element);

struct Node* sort(struct Node *n, char element, char member);

int main()
{
    struct Node* head = NULL;
    char inputVoornaam[MAX] = {0};
    int keuze = 0;
    int element = 0;

    head = (struct Node*)malloc(sizeof (struct Node));
    head->next = NULL;
    head = push(head, -2);

    printList(head);

    do
    {
        printf("wat wil je doen?\n0 -> stoppen\n1 -> lijst printen\n2-> student printen\n3 -> data toevoegen\n4 -> data verwijderen\n5 -> sorteren\n");
        gets(inputVoornaam);
        keuze = atoi(inputVoornaam);
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
                printf("welke student wil je printen? geef de achternaam in. ");
                gets(inputVoornaam);
                printStudent(head,inputVoornaam);
            case 3:
                printf("op welke plaats wil je het woord toevoegen? -1 voor laatste, 0 voor eerste. ");
                do
                {
                    gets(inputVoornaam);
                    element = atoi(inputVoornaam);
                    //printf("%d\n",element);
                    if (element < -1)
                    {
                        printf("Plaatsen kunnen niet kleiner dan -1 zijn. ");
                    }
                }while (element < -1);
                //printf("woord: %s element: %d\n",inputVoornaam, element);
                head = push(head, element);
                break;
            case 4:
                printf("op welke plaats wil je een woord verwijderen? -1 voor laatste, 0 voor eerste. ");
                do
                {
                    gets(inputVoornaam);
                    element = atoi(inputVoornaam);
                    {
                        printf("Plaatsen kunnen niet kleiner dan -1 zijn. ");
                    }
                }while (element < -1);
                strcpy(inputVoornaam,pop(&head, element));
                printf("%s\n",inputVoornaam);
                break;
            case 5:
                printf("Op wat wil je sorteren?\n0 -> Voornaam\n1 -> Achternaam\n2 -> leeftijd\n3 -> totale score\n4 -> geslacht\n");
                do
                {
                    gets(inputVoornaam);
                    keuze = atoi(inputVoornaam);
                    if (keuze < 0 || keuze > 4)
                    {
                        printf("de parameter moet tussen 0 en 4 liggen. ");
                    }
                }while (keuze < 0 || keuze > 4);
                printf("hoe wil je sorteren? 0 voor van A naar Z of laag naar hoog en 1 voor van Z naar A of hoog naar laag. ");
                do
                {
                    gets(inputVoornaam);
                    element = atoi(inputVoornaam);
                    if (element != 0 && element != 1)
                    {
                        printf("de parameter kan niet anders zijn dan 1 of 0. ");
                    }
                }while (element != 0 && element != 1);
                head = sort(head, element, keuze);
                break;
            default:
                printf("Er is geen juist comando ingegeven");
                break;

        }

    }while(1);
}

void printList(struct Node* n)
{
    int counter = 0;
    char pause[MAX];
    system("cls");
    printf("De lijst\nVoornaam\t%c\tAchternaam\t%c\tleeftijd\t%c\ttotale score\t%c\tgeslacht\t%c\n",186,186,186,186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    while (n != NULL)
    {
        printf("%s\t", n->Voornaam);
        while (n->Voornaam[counter] != '\0')
        {
            counter ++;
        }
        if(counter < 8)
        {
            printf("\t");
        }
        counter = 0;
        printf("%c\t%s\t",186, n->Achternaam);
        while (n->Achternaam[counter] != '\0')
        {
            counter ++;
        }
        if(counter < 8)
        {
            printf("\t");
        }
        printf("%c\t%d\t\t%c\t%.2f\t\t%c\t",186, n->leeftijd,186, n->totaleScore,186);
        switch (n->geslacht)
        {
        case 0:
            printf("Man\t\t%c\n",186);
            break;
        case 1:
            printf("Vrouw\t\t%c\n",186);
            break;
        case 2:
            printf("onzijdig\t%c\n",186);
            break;
        default:
            printf("error\t\t%c\n",186);
            break;
        }

        n = n->next;
    }
    gets(pause);
}

void printStudent (struct Node* n, char *achternaam)
{
    int counter = 0;
    char exit = FALSE;
    while(strcmp(n->Achternaam,achternaam) != 0 && exit == FALSE)
    {
        n = n->next;
        if(n->next == NULL)
        {
            exit = TRUE;
        }
    }
    if (exit == TRUE)
    {
        printf("Student niet gevonden \n");
    }
    else
    {
        printf("De lijst\nVoornaam\t%c\tAchternaam\t%c\tleeftijd\t%c\ttotale score\t%c\tgeslacht\t%c\n",186,186,186,186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
        printf("%s\t", n->Voornaam);
        while (n->Voornaam[counter] != '\0')
        {
            counter ++;
        }
        if(counter < 8)
        {
            printf("\t");
        }
        counter = 0;
        printf("%c\t%s\t",185, n->Achternaam);
        while (n->Achternaam[counter] != '\0')
        {
            counter ++;
        }
        if(counter < 8)
        {
            printf("\t");
        }
        printf("%c\t%d\t\t%c\t%.2f\t\t%c\t",185, n->leeftijd,185, n->totaleScore,185);
        switch (n->geslacht)
        {
        case 0:
            printf("Man\t\t%c\n",186);
            break;
        case 1:
            printf("Vrouw\t\t%c\n",186);
            break;
        case 2:
            printf("onzijdig\t%c\n",186);
            break;
        default:
            printf("error\t\t%c\n",186);
            break;
        }
    }
}

void freeList(struct Node* n)
{
    struct Node* next = NULL;

    while (n != NULL)
    {
        next = n->next;
        free(n->Voornaam);
        free(n->Achternaam);
        free(n);
        n = next;
    }
}

struct Node* push(struct Node *n,char element)
{
    struct Node* head = n;
    struct Node* next = n->next;
    int counterVoornaam = 0;
    int counterAchternaam = 0;
    int leeftijd = 0;
    float totaleScore = 0.0;
    char geslachtString[MAX] = {0};
    geslacht geslacht = Onzijdig;
    char voornaam[MAX] = {0};
    char achternaam[MAX] = {0};


    printf("wat is de voornaam? ");
    gets(voornaam);
    printf("wat is de achternaam? ");
    gets(achternaam);
    printf("wat is de leeftijd? ");
    gets(geslachtString);
    leeftijd = atoi(geslachtString);
    printf("wat is de totale Score? ");
    gets(geslachtString);
    totaleScore = atof(geslachtString);
    printf("wat is het geslacht? ");
    gets(geslachtString);

    if(strncmp(geslachtString,"Man",3)==0)
    {
        geslacht = Man;
    }
    if(strncmp(geslachtString,"Vrouw",5)==0)
    {
        geslacht = Vrouw;
    }


    while (voornaam[counterVoornaam] != '\0')
    {
        counterVoornaam ++;
    }
    //printf("%d\n",counterVoornaam);

    while (voornaam[counterAchternaam] != '\0')
    {
        counterAchternaam ++;
    }
    //printf("%d\n",counterVoornaam);

    if (element == 0)
    {
        //printf("head \n");
        n = (struct Node*)malloc(sizeof (struct Node));
        n->next = head;
        head = n;
    }
    else if(element > -2)
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
            n->next = next;
    }
    n->Voornaam = (char*)calloc(sizeof (char), counterVoornaam);
    n->Achternaam = (char*)calloc(sizeof (char), counterAchternaam);
    strcpy(n->Voornaam,voornaam);
    strcpy(n->Achternaam,achternaam);
    n->leeftijd = leeftijd;
    n->totaleScore = totaleScore;
    n->geslacht = geslacht;

    return head;
}

char *pop(struct Node **n, char element)
{
    struct Node* head = *n;
    struct Node* index = *n;
    struct Node* indexNext = index->next;
    char Voornaam[MAX] = {0};
    char *pointer = NULL;

    if(element == 0)
    {
        strcpy(Voornaam,head->Voornaam);
        index = index->next;
        free(head->Voornaam);
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
        strcpy(Voornaam,indexNext->Voornaam);
        index->next = indexNext->next;
        free(indexNext->Voornaam);
        free(indexNext);
    }



    *n = head;
    pointer = Voornaam;
    return pointer;
}

struct Node* sort(struct Node *n, char element, char member)
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
            if(member == 0 || member == 1)
            {
                for(int k = 0; k<MAX && exit == FALSE;k++)
                {
                    if (member == 0 )
                    {
                        exit = TRUE;
                        if(n->Voornaam[k] > next->Voornaam[k] && element == 0)
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
                        else if(n->Voornaam[k] < next->Voornaam[k] && element == 1)
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
                        else if(n->Voornaam[k] == next->Voornaam[k])
                        {
                            exit = FALSE;
                        }
                    }
                    else
                    {
                        exit = TRUE;
                        if(n->Achternaam[k] > next->Achternaam[k] && element == 0)
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
                        else if(n->Achternaam[k] < next->Achternaam[k] && element == 1)
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
                        else if(n->Achternaam[k] == next->Achternaam[k])
                        {
                            exit = FALSE;
                        }
                    }
                }
            }
            else if(member == 2)
            {
                if(n->leeftijd > next->leeftijd && element == 0)
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
                else if(n->leeftijd < next->leeftijd && element == 1)
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
            }
            else if(member == 3)
            {
                if(n->totaleScore > next->totaleScore && element == 0)
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
                else if(n->totaleScore < next->totaleScore && element == 1)
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
            }
            else if(member == 4)
            {
                if(n->geslacht > next->geslacht && element == 0)
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
                else if(n->geslacht < next->geslacht && element == 1)
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
            }
            exit = FALSE;
            //printf("%d ",n->Voornaam);
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

