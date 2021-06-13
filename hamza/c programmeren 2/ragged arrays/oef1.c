#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringlengte(char *string)
{
	int lengte = strlen(string);
	return lengte;
}


int main(){
	
	char testData[] = "C-programmeren 2";
	
	int lengte = stringlengte(testData);
	printf("de lengte van de string : %s is %d",testData,lengte);
	
	return 0;
	
}

