
#include <stdio.h>

int main()
{
    int k = 0, b = 1, c = 2, d = 3, m, a[3];
    int *p[] = {&k, &b, &c, &d};
    for(m = 0; m < 3; m++)
        a[*p[m]] = **(p+m+1);
    printf("%d, %d, %d",a[0],a[1],a[2]);
    return 0;

}
