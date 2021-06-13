#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#DEFINE AANTAL_VRAGEN 10
#DEFINE MAX_LENGTE 50


int main(){
	short int counter = 0;
	char naam[AANTAL_VRAGEN][MAX_LENGTE];
	
	while(counter < AANTAL_VRAGEN)
	{
		gets(naam[counter]);
		counter++;
	}
	
	
	return 0;
	
}

