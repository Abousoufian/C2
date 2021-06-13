#include <stdio.h>
#include <string.h>

void sorteren(char temp_naam[][50])
{
	char swap[50]="";
	
	for(int i = 0; i < 9; i++)
	{
		for(int j = i + 1; j < 10; j++)
		{
			if(strcmp(temp_naam[i],temp_naam[j]) > 0)
			{
				strcpy(swap,temp_naam[i]);
				strcpy(temp_naam[i],temp_naam[j]);
				strcpy(temp_naam[j],swap);
				
			}
			
		}
	}
	
	printf("\n");
	for(int i = 0; i < 10; i++)
	{
		printf("%s\n",temp_naam[i]);
	}
}



int main(){
	
	char naam[10][50];
	
	printf("geef maximaal 10 namen met een maximale lengte van 50\n");
	for(int i = 0; i < 10; i++)
	{
		scanf("%s",naam[i]);
	}
	
	sorteren(naam);
	/*for(int i = 0; i < 10; i++)
	{
		printf("%s\n",naam[i]);
	}*/
	
	return 0;
	
}

