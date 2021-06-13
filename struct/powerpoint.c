#include <stdio.h>
#include <string.h>

# define MAX 20

struct mario
{
	char name[20];
	int lives;
	int coins;
};

typedef struct
{
	char name[20];
	int lives;
	int coins;
}luigi;

void printStats(struct mario x);

int main()
{
	struct mario speler1;
	luigi speler2;
	
	strcpy(speler1.name, "soufian");
	speler1.lives = 3;
	speler1.coins = 0;
	
	printStats(speler1);
	
	strcpy(speler2.name, "saad");
	speler2.lives = 3;
	speler2.coins = 0;
	
	printf("%s\n", speler2.name);
	printf("%d\n", speler2.lives);
	printf("%d\n", speler2.coins);
    return 0;
}

void printStats(struct mario x)
{
	printf("%s\n", x.name);
	printf("%d\n", x.lives);
	printf("%d\n", x.coins);
}