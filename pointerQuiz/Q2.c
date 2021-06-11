#include <stdio.h>
#include <stdlib.h>
int main () 
{
   char gs_1[10]="";
   char gs_2[10]="";
   
   int getal1=0;
   int getal2=0;
   
   int *g1Ptr=&getal1;
   int *g2Ptr=&getal2;
   
   
   printf("Geef het eerste getal in: ");
   gets(gs_1);
   
   printf("Geef het tweede getal in: ");
   gets(gs_2);
   
   getal1=atoi(gs_1);
   getal2=atoi(gs_2);
   
   printf("Getal 1: %d\n", getal1);
   printf("Getal 2: %d\n", getal2);
   
   
   printf("Adress van Getal 1: %p\n", &getal1);
   printf("Adress van Getal 1 via pointer: %p\n", g1Ptr);
   printf("waarde van g1Ptr: %d\n", *g1Ptr);
   printf("Adress van g1Ptr: %p\n", &g1Ptr);
   
   printf("Adress van Getal 2: %p\n", &getal2);
   printf("Adress van Getal 2 via pointer: %p\n", g2Ptr);
   printf("waarde van g2Ptr: %d\n", *g2Ptr);
   printf("Adress van g2Ptr: %p\n", &g2Ptr);
   
   return 0;
}
