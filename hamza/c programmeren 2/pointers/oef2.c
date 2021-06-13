#include <stdio.h>
#include <stdlib.h>
//EIGENLIJK OEF 4
void print_adres(int x){
	printf("het adres = %p\n", &x);
	
}


int main(){
	
	int var = 10;
	
	printf("het adres = %p\n", &var);
	print_adres(var);
//	printf("de waarde is %d",adres);
	
	return 0;
	
	
	
	
}