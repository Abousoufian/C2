#include <stdio.h>
#include <math.h>

int main()
{
    double *pointer;
    double i = 0.0;

    printf("geef een kommagetal in: ");
    scanf(" %lf", &i);
    pointer = &i;
    i = fabs(i);
    printf("%lf\n", *pointer);
}
