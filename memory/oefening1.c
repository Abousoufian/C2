#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>



int main()
{
	int lengte = 0;
	
	printf("Geef de lengte van string in: ");
	scanf("%d", &lengte);
	
	unsigned char *string = (unsigned char *) calloc(lengte, sizeof(unsigned char));
	
	printf("Geef de tekst van %d characters nu in: ", lengte);
	scanf("%s",string);
	printf("De ingegeven tekst: %s", string);
	return 0;
}

