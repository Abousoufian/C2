#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// als ge pointer naar andere pointer wilt hebbe dan hoeft ge geen &-teken te doen
int som(int a,int b){return(a + b);}
int verschil(int a, int b){return(a - b);}

int main(){
	
	int getal1 = 0;
	int getal2 = 0;
	int uitkomst = 0;
	char input[10] = "";
	int (*fptrtemp) (int, int) = NULL;
	int (*fptrsom) (int, int) = &som;
	int (*fptrverschil) (int, int) = &verschil;
	
	printf("wil je optellen of aftrekken\n");
	gets(input);
	
	if(strcmp(input,"optellen") == 0 )
	{
		fptrtemp = fptrsom;
	}
	else if(strcmp(input,"aftrekken") == 0)
	{
		printf("wafel\n");
		fptrtemp = fptrverschil;
	}
	
	
	printf("geef 2 getallen\n");
	scanf("%d",&getal1);
	scanf("%d",&getal2);
	
	
	uitkomst = fptrtemp(getal1,getal2);
	// uitkomst = fptrverschil(getal1,getal2);
	printf("de resultaat is %d\n",uitkomst);
	
	
	
	return 0;
	
}

