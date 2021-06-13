#include <stdio.h>

int main()
{
    int *p1, sum;
    float *p2, *p3, grade, max = 0;
    p1 = &sum;
    p2 = &grade;
    p3 = &max;

    do{
        printf("wat is het punt van de student? ");
        scanf("%f", p2);
        if(*p2 >=5 && *p2 <= 10)
        {
            *p1 +=1;
        }
        if(*p2 > *p3)
        {
            *p3 = *p2;
        }
        printf("het aantal studenten tussen 5 en 10: %d \nHet hoogste punt is: %f ",*p1, *p3);
    }while(*p2 != -1);

}
