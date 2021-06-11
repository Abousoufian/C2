#include <stdio.h>
int main(void)
{
	int *ptr1;
	int i = 10;
	double *ptr2;
	double j = 1.234;
	ptr1 = &i;					
	ptr2 = &j;						
	*ptr1 = *ptr2;																
	printf("%d %u %u %u\n", i, sizeof(ptr1), sizeof(ptr2),sizeof(*ptr2)); 
	return 0;
}
/*
	lijn 4: pointer "int *ptr1" aangemaakt
	lijn 5: int variable i is aangemaakt en heeft waarde 10
	lijn 6: pointer "double *ptr2" aangemaakt
	lijn 7: double variable j is aangemaakt en heeft waarde 1.234
	lijn 8: "ptr1" wijst naar adress locatie i
	lijn 9: "ptr2" wijst naar adress locatie j
	lijn 10: *ptr1 krijgt waarde 1.234 is een int dus 1 en ook i krijgt 1
	lijn 11: print 1 4 4 8 uit
			pointer heeft altijd size 4BYTE
*/