#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	
	char str[30] = "kat;12 jaar;zwart";
	char str2[30] = "hond;4 jaar;paars";
	char dier[30] = "";
	char jaar[30] = "";
	char kleur[30] = "";
	char *token;
	const char s[2] = ";";// teken waarop er gespaced word (delimiter)
	
	
	token = strtok(str , s);
	
	while( token != NULL ) 
	{
      printf( " %s\n", token );
	  switch (category)
	  {
		  case 1: strcpy(dier , token);
		  case 2: strcpy(jaar , token);
		  case 3: strcpy(kleur , token);
		  
	  }
	  
      token = strtok(NULL, s);
   }
	printf("%s",dier);
	printf("%s",jaar);
	printf("%s",kleur);

	
	
	
	
	
	
	
	
	
	return 0;
}