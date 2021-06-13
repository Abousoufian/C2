#include <stdio.h>
#include <stdlib.h>

void printArray(char **lijst, int lengte)
{
	printf("%d\n",lengte);
	for(int i = 0; i < lengte; i++)
	{
		printf("%s\n",lijst[i]);
	}
	
}
char* array[3][10] = {"strings","zijn","gay"};//geen accolades per woord

int main(){
	
	printArray(*array,3);
	
	// for(int i = 0; i < 3; i++)
	// {
		// printf("%s ",*array[i]);
	// }
	
	return 0;
	
}

