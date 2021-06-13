#include <stdio.h>
#include <stdlib.h>


#define BESTAND "C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\file_handeling\\oef1.txt"


int main()
{
	FILE *fp = NULL;
	char ch;
	
	fp = fopen (BESTAND , "r");
	
	printf("de data dat erin staat is:\n");
	while((ch = fgetc(fp)) != EOF)
    {	
		printf("%c", ch);
		
	}
	
	
	
	fclose(fp);
	
	
	return 0;
}

