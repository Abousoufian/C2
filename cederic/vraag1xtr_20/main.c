#include <stdio.h>

#define AANTAL 10

int main()
{
    float array[AANTAL]= {0};
    float *point, *ref, *ptmin, *ptmax;

    point = array;
    ref = array;

    while(point-ref < 10)
    {
        do
        {
        printf("wat is het punt van student nr %d? ", (int)(point-ref)+1);
        scanf("%f",point);
        }while(*point < 0 || *point >10);
        point += 1;
    }
    point = array;
    ptmin = point;
    ptmax = point;
    while(point-ref < 10)
    {
        if (*ptmin > *point)
            ptmin = point;
        if(*ptmax < *point)
            ptmax = point;
        point += 1;
    }
    printf("het laagste punt is %.1f van student nr %d\n", *ptmin, (int)(ptmin-ref)+1);
    printf("het hoogste punt is %.1f van student nr %d\n", *ptmax, (int)(ptmax-ref)+1);
}
