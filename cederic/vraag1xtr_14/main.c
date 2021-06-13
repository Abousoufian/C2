#include <stdio.h>

int main()
{
    int *p1, *p2, i = 0, mul = 0;
    p1 = &i;
    p2 = &mul;

    *p1 = 10;
    *p2 = 10;

    while(*p1 <= 20)
    {
        while(*p2 <= 20)
        {
            printf("%d * %d = %d\n", *p1, *p2, *p1 * *p2);
            *p2 += 2;
        }
        *p1 += 2;
        *p2 = *p1;
    }

}
