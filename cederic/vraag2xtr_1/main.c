#include <stdio.h>

double sum(double A, double B) {return(A+B);}
double subtract(double A, double B) {return (A-B);}

int main()
{
    double number1 = 0.0, number2 = 0.0;
    double (*pt1)(double, double) = &sum;
    double (*pt2)(double, double) = &subtract;

    printf("geef 2 getallen in: ");
    scanf(" %lf %lf",&number1,&number2);

    printf("som: %.1lf\nverschil %.1lf\n",pt1(number1,number2),pt2(number1,number2));
}
