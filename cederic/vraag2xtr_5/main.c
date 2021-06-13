#include <stdio.h>
#include <stdlib.h>

int compair (const void *a, const void *b);

int main()
{
    int size = 1;
    int values[100] = {};

    printf("hoeveel waardes heb je? ");
    scanf(" %d",&size);
    for(int i = 0;i<size;i++)
    {
        printf("geef getal %d in ",i+1);
        scanf(" %d",&values[i]);
    }
    for(int i = 0;i<size;i++)
    {
        printf("%d ",values[i]);
    }
    printf("\n");
    qsort(values,size,sizeof (int), compair);

    for(int i = 0;i<size;i++)
    {
        printf("%d ",values[i]);
    }

}

int compair (const void *a, const void *b)
{
    if((*(int*)a)%2 ==0 && (*(int*)b)%2 ==1)
    {
        return -1;
    }
    else if((*(int*)a)%2 ==1 && (*(int*)b)%2 ==0)
    {
        return 1;
    }
    else
    {
       return(*(int*)a-*(int*)b);
    }
}
