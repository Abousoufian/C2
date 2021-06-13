#include <stdio.h>
#include <stdlib.h>

 void new_integer(void){
	int var = 12;
	printf("%p\n",&var);
	//ge moogt geen adress returnen
}


int main(){
	new_integer();
	
	
	return 0;
	
	
	
	
}