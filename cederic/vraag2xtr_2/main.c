#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d4(){return((rand()% 4)+1);}
int d6(){return((rand()% 6)+1);}
int d8(){return((rand()% 8)+1);}
int d10(){return((rand()% 10)+1);}
int d12(){return((rand()% 12)+1);}
int d20(){return((rand()% 20)+1);}

int maxOfMultipleDice(int amount, int (*dice)());

int main()
{
    srand(time(NULL));
    printf("het hoogste getal op 1 van de 5 d12 dobbelstenen is %d\n", maxOfMultipleDice(5,&d12));

}

int maxOfMultipleDice(int amount, int (*dice)())
{
    int max = 0;
    int roll = 0;
    for(int i = 0; i<amount; i++)
    {
        roll = dice();
        if(roll>max)
        {
            max = roll;
        }
    }
    return max;
}
