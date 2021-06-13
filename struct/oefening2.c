#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct meting
{
	double meetwaarde;
	unsigned long long int timestamp;
};

void gemiddeldeF(struct meting *x, struct meting *y, double *gemiddelde);

int main(int argc, char *argv[])
{
	struct meting m1;
	struct meting m2;
	double gemiddelde=0.0;
	
	srand(time(NULL));
	
	m1.meetwaarde = rand()%5001;
	printf("%.3lf\n", m1.meetwaarde);
	m1.timestamp = time(NULL);
	printf("%d\n", m1.timestamp);
	m2.meetwaarde = rand()%5001;
	printf("%.3lf\n", m2.meetwaarde);
	m2.timestamp = time(NULL);
	printf("%d\n", m2.timestamp);	

	gemiddeldeF(&m1, &m2, &gemiddelde);
	printf("gemiddelde = %f\r\n", gemiddelde); 
	return 0;
}


void gemiddeldeF(struct meting *x, struct meting *y, double *gemiddelde)
{
	*gemiddelde = (x->meetwaarde + y->meetwaarde) / 2;
}