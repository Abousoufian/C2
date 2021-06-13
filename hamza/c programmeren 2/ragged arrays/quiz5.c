#include <stdio.h>
#include <stdlib.h>
//zonder sterretje verwijst ptr naar het element
//met sterretje verwijst pointer naar het element van de array
//is Q16
int main(){
	
	int *ptr, arr[] = {10,20,30,40,50};
	ptr = arr;//ptr = 10 want *ptr = 0 en element nul is 10
	printf("%d\n", *ptr);
	*ptr = 3;//ptr = 3. sinds het verwijst naar 0de element verandert die de 10 naar 3
	printf("%d\n", *ptr);
	ptr += 2;// ptr heeft nu de waarde 2 en verwijst naar element 2
	printf("%d\n", *ptr);
	*ptr = 5;// ptr verwijst naar element 2. en verandert de waarde van 30 naar 5
	
	for(int i = 0; i < 5; i++)
	{
		printf("%d    ",arr[i]);
	}
	printf("\n");
	printf("%d\n",arr[0]+arr[2]);// 3 + 5 wordt 8

	return 0;
	
}

