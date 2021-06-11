#include <stdio.h>
int main(void)
{
	int *ptr;
	int i = 10;
	ptr = &i;
	i += 20;
	
	printf("%d\n", *ptr);
	return 0;
}

/*
	lijn 4: pointer is aangemaakt, op dit moment neemt de pointer een willekeurige adress
			en in deze adress zal een willekeurige waarde in zitten, hierdoor gaat de pointer
			naar een willekeurige adress wijzen, bad habit, maak er een gewoonte om int *ptr=NULL te gebruiken
	lijn 5: int variabele aangemaakt met waarde 10
	lijn 6: "ptr" wijst naar adress locatie van "i"
	lijn 7: 10+20=30 "i" krijgt waarde 30
	lijn 9: je print nu de waarde naar waar "ptr" naar wijst dus 30
*/