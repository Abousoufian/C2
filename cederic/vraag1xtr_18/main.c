#include <stdio.h>

#define DAYS 31
int main()
{
    int i = 0;
    double temp, array[DAYS] = {0};
    double *pt, *ptref;

    pt = array;
    ptref = array;

    for(int j = 0; j < 31; j++)
    {
        printf("temperatuur dag %d ", j+1);
        scanf("%lf",pt);
        //printf("de temp is: %lf\n", *pt);
        pt += 1;
    }
    pt =array;

    printf("wat is de temp vandaag?");
    scanf("%lf", &temp);
    while(*pt>temp)
    {
        pt +=1;
    }
    printf("%d",(int)(pt-ptref));
}
