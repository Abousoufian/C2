#include <stdio.h>

#define DAYS 31
int main()
{
	double temp;
	double array[DAYS] = {0};
    double *pt;
	double *ptref;

	pt = array;
    ptref = array;

    for(int i = 0; i < 31; i++)
    {
        printf("temperatuur dag %d ", i+1);
        scanf("%lf",pt);
        //printf("de temp is: %lf\n", *pt);
        pt += 1;
    }
	
    pt=array;

    printf("wat is de temp vandaag?");
    scanf("%lf", &temp);
    while(*pt>temp)
    {
        pt +=1;
    }
    printf("%d",(int)(pt-ptref));
	
	return 0;
}