#include <stdio.h>
int main(void)
{
	int *ptr;
	int arr[] = {10, 20, 30, 40, 50};
	ptr = arr;
	*ptr = 3;
	ptr += 2;
	*ptr = 5;
	printf("%d\n", arr[0]+arr[2]);
	return 0;
}
/*
	lijn 4: pointer wordt aangemaakt
	lijn 5: int array wordt aangemaakt
	lijn 6: "ptr" point naar eerste adress "arr", dus index 0 met waarde 10
	lijn 7: omdat de pointer op index 0 wijst van arr wordt 10 nu 3
	lijn 8: "ptr" point twee  adressen verder van "arr", dus index 2 met waarde 30
	lijn 9: omdat de pointer op index 2 wijst van arr wordt 30 nu 5
	lijn 10: 3 + 5 = 8, 8 wordt uitgeprint	
*/