#include <stdio.h>


int main(int argc, char *argv)
{
	printf("argument count: %d\n", argc);
	
	for(int i=0; i<argc; i++)
	{
		printf("argument %d: %s\n", i, argv);
	}

	return 0;
}
