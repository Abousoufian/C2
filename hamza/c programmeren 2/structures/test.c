#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct meting
{

	double meetwaarde;

	unsigned long long int timestamp;

};

double rand_float() {
    return ((double)(rand() % 500) )/ 100.0;//de random functie een int laten maken en dan typecasten naar double
}

int main()
{
	struct meting S1,S2;
	srand(time(NULL));

	
	for(int i = 0; i < 2; i++)
	{
		S1.meetwaarde = rand_float();
		printf("meetwaarde %d: %lf\n",i+1,S1.meetwaarde);
	}
	
	
	return 0;
}

