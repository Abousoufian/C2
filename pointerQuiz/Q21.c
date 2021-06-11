#include <stdio.h>
int main(void)
{
	int *ptr1;
	int *ptr2;
	int i = 10;
	int j = 20;
	
	ptr1 = &i;				// ptr1 krijgt adress waarde van i
	*ptr1 = 150;			// waarde van i verandert van 10 naar 150
	ptr2 = &j;				// ptr2 krijgt adress waarde van j
	*ptr2 = 50;				// waarde van j verandert van 20 naar 50
	ptr2 = ptr1;			// ptr2 krijgt adress waarde van ptr1 en ptr1 had adress van i
	*ptr2 = 250;			// waarde van i verandert van 150 naar 250
	ptr1 = ptr2;			// ptr1 krijgt adress waarde van ptr2 en ptr2 had adress van i
	*ptr1 += *ptr2;			// waarde van i verandert van 250 naar 500
	printf("%d\n", i+j);	// print 550 uit
	return 0;
}
