#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int stringLengte (char *string);

int main()
{
    char testData[500] = {0};
    int lengte = 0;

    printf("geef een zin in:\n");
    gets(testData);

    lengte = stringLengte(testData);
    printf("%d",lengte);
}

int stringLengte (char *string)
{
    int counter = 0;
    int exit = FALSE;
    for(int i = 0; exit == FALSE; i++)
    {
        counter ++;
        if (string[i] == '\0')
        {
            counter --;
            exit = TRUE;
        }
    }
    return counter;
}
