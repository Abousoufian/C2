#include <stdio.h>
int main(void)
{
    int *p, i = 1;

    p = &i;

    while (*p<=10)
    {
        printf("%d\n",*p);
        *p += +1;
    }
}

