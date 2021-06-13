#include <stdio.h>

int main()
{
    int *p1, *p2, *p3, i = 0, j = 0, sum = 0;
    p1 = &i;
    p2 = &j;
    p3 = &sum;

    do
    {
        printf("geef 2 getallen onder de 100 op. het eerste getal is ook kleiner dan het 2de. ");
        scanf(" %d %d",p1, p2);
    }while(*p1 > *p2 || *p1 > 100 || *p2 > 100);

    *p1 += 1;
    //printf("%d, %d\n", *p1, *p2);
    while(*p1 < *p2)
    {
        *p3 += *p1;
        //printf("%d, %d\n", *p1, *p3);
        *p1 += 1;
    }
    printf("%d\n",*p3);
}
