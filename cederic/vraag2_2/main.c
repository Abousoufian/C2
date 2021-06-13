#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define AANTAL 5


char sorteren (char a[], char z[]);

int main()
{
    char name[AANTAL][50] = {};
    for (int i=0; i<AANTAL; i++)
    {
        printf("typ naam nr %d: ", i+1);
        gets(name[i]);
    }
    for(int i = 0; i<AANTAL; i++)
    {
        for(int j = 0; j<AANTAL-1; j++)
        {
            sorteren (name[j],name[j+1]);
        }
    }
    for (int i=0; i<AANTAL; i++)
    {
        printf("naam nr %d: %s\n", i+1,name[i]);
    }
}


char sorteren (char *a, char *z)
{
    char tijdelijk[50]={0};
    char exit = FALSE;
    for (int i = 0; i<10 && exit == FALSE; i++)
    {
        if(a[i] > z[i])
        {
            strcpy(tijdelijk , a);
            strcpy(a , z);
            strcpy(z , tijdelijk);
            return TRUE;
        }
        if(a[i] < z[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}
