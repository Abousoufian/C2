#include <stdio.h>
#include <math.h>
int main () 
{
   double getal1=0;
   double getal2=0;
   
   double *g1Ptr=&getal1;
   double *g2Ptr=&getal2;
   
   printf("Geef het eerste getal in: ");
   scanf("%lf", &getal1);
   
   printf("Geef het tweede getal in: ");
   scanf("%lf", &getal2);
    
   printf("Getal 1: %.2lf\n", getal1);
   printf("Getal 2: %.2lf\n", getal2);
   
   printf("waarde van g1Ptr: %.2lf\n", fabs(*g1Ptr));
   printf("waarde van g2Ptr: %.2lf\n", fabs(*g2Ptr));
   
   return 0;
}
