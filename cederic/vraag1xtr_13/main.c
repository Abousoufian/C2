#include <stdio.h>

void sort (float *pointer1, float *pointer2);

int main()
{
    float *ptr1, *ptr2, *ptr3, point1 = 0, point2 = 0, point3 = 0;
    ptr1 = &point1;
    ptr2 = &point2;
    ptr3 = &point3;

    printf("geef de 3 punten van de student in. ");
    scanf(" %f %f %f", ptr1, ptr2, ptr3);

    if(*ptr1 < 5 || *ptr2 < 5 || *ptr3 < 5)
    {
        printf("het gemiddelde is: %f", (*ptr1+*ptr2+*ptr3)/3);
    }
    else
    {
        for(int i = 0; i<3 ; i++)
        {
            sort (ptr1, ptr2);
            sort (ptr2, ptr3);
        }
        printf("dit zijn de punten: %.1f %.1f %.1f", *ptr1, *ptr2, *ptr3);
    }
}

void sort (float *pointer1, float *pointer2)
{
    float placehorlder = 0;
    if(*pointer1 >*pointer2)
    {
        placehorlder = *pointer1;
        *pointer1 = *pointer2;
        *pointer2 = placehorlder;
    }
}

