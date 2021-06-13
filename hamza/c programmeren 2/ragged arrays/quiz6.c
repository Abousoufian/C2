#include <stdio.h>
#include <stdlib.h>
// is Q17

int main(){
	
	int i = 10, *p = &i;
	p[0] = 50;
	printf("int i = %d\n",i);//i wordt 50 omdat p verandert word naar 50
	printf("%d\n", i+p[0]);// dus 50 + 50 = 100

	return 0;
	
}

