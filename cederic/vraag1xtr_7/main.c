#include <stdio.h>

int main(void)
{
    double number1 = 0.0, number2 = 0.0;
    double *pointer1 = &number1, *pointer2 = &number2;

    printf("geef kommagetal 1 in: ");
    scanf(" %lf", &number1);
    printf("geef kommagetal 2 in: ");
    scanf(" %lf", &number2);

    double placehorlder = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = placehorlder;

    if(*pointer1 > *pointer2)
    {
        printf("de grootste is %lf en de kleinste %lf", *pointer1, *pointer2);
    }
    else
    {
        printf("de grootste is %lf en de kleinste %lf", *pointer2, *pointer1);
    }
}
