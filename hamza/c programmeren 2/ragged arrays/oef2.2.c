#include <stdio.h>
#include <string.h>

// void sorteren(char temp_naam[][50])
// {
	// char swap[] = "";
	// printf("%s",temp_naam);
	// for(int i = 0; i < 10-1; i++)
	// {
		// for(int j = 0; j < 10-i-1; j=+1)
		// {
			// if(temp_naam[j+1] < temp_naam[j])
			// {
				// if(strcmp(temp_naam[j],temp_naam[j+1]) <= 0)
				// {
					// strcpy(swap,temp_naam[j]);
					// strcpy(temp_naam[j],temp_naam[j+1]);
					// strcpy(temp_naam[j+1],swap);
					// printf("%c",temp_naam[j]);
				// }
			// }
		// }
	// }
	// for(int i = 0; i < 10; i++)
	// {
		// printf("%c\n",temp_naam[i]);
	// }
// }

int main(){
	
	char naam[10][50];
	char swap[50]="";
	int max = 10;
	printf("geef maximaal 10 namen met een maximale lengte van 50\n");
	for(int i = 0; i < max; i++)
	{
		// scanf("%s",naam[i]);
		scanf("%s",naam[i]);
	}
	
	for(int i = 0; i < max - 1; i++)
	{
		for(int j = i + 1; j < max; j++)
		{
			if(strcmp(naam[i],naam[j]) > 0)
			{
				strcpy(swap,naam[i]);
				strcpy(naam[i],naam[j]);
				strcpy(naam[j],swap);
				
			}
			
		}
	}
	
	printf("\n");
	for(int i = 0; i < 10; i++)
	{
		printf("%s\n",naam[i]);
	}
	
	
	// sorteren(naam);
	/*for(int i = 0; i < 10; i++)
	{
		printf("%s\n",naam[i]);
	}*/
	
	
	
	
	return 0;
	
}

