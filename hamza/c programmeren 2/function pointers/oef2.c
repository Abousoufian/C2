#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d4()	{ return ( (rand() % 4 ) + 1); }
int d6() 	{ return ( (rand() % 6 ) + 1); }
int d8()	{ return ( (rand() % 8 ) + 1); }
int d10()	{ return ( (rand() % 10 ) + 1); }
int d12()	{ return ( (rand() % 12 ) + 1); }
int d20()	{ return ( (rand() % 20 ) + 1); }

int maxOfMultipleDice(int aantal, int (*ptr) () ){
	int som = 0;
	for(int i = 0; i < aantal; i++)
	{
		if(som < ptr())
		{
			som = ptr();
		}
		else
		{
			continue;
		}
		
	}
	return som;
}

int main()
{
	srand(time(NULL));
	int waarde = 0;
	int aantal = 0; 
	int dobbelsteen = 0;
	printf("met welke dobbelsteen wil je gooien\n");
	scanf("%d",&dobbelsteen);
	
	switch(dobbelsteen)
	{
		case 4: waarde = maxOfMultipleDice(5, &d4);
		case 6: waarde = maxOfMultipleDice(5, &d6);
		case 8: waarde = maxOfMultipleDice(5, &d8);
		case 10: waarde = maxOfMultipleDice(5, &d10);
		case 12: waarde = maxOfMultipleDice(5, &d12);
		case 20: waarde = maxOfMultipleDice(5, &d20); 		
	}
	
	printf("de geworpen waarde is %d\n",waarde);
	
	
	return 0;
}


