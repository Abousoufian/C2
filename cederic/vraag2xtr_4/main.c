#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d4(){/*printf("d4\n")*/;return((rand()% 4)+1);}
int d6(){/*printf("d6\n")*/;return((rand()% 6)+1);}
int d8(){/*printf("d8\n")*/;return((rand()% 8)+1);}
int d10(){/*printf("d10\n")*/;return((rand()% 10)+1);}
int d12(){/*printf("d12\n")*/;return((rand()% 12)+1);}
int d20(){/*printf("d20\n")*/;return((rand()% 20)+1);}

typedef int (*DICE)();

DICE getDiceByThrownDice(int startDice) ;

int main()
{
    srand(time(NULL));
    int stdice = 0;

    printf("geef een dobbelsteen om te bepalen met welke je gooit. ");
    scanf(" %d",&stdice);

    switch(stdice)
    {
        case(4):
            stdice = 0;
            break;
        case(6):
            stdice = 1;
            break;
        case(8):
            stdice = 2;
            break;
        case(10):
            stdice = 3;
            break;
        case(12):
            stdice = 4;
            break;
        case(20):
            stdice = 5;
            break;
    }

    printf("dit heb je geworpen= %d\n",getDiceByThrownDice(stdice)());
}

DICE getDiceByThrownDice(int startDice)
{
    int number = 0;
    int (*di[])() = {&d4,&d6,&d8,&d10,&d12,&d20};

    number = di[startDice]();
    while(number >= 7)
    {
        if(number < 9)
        {
            number = di[2]();
        }
        else if(number < 11)
        {
            number = di[3]();
        }
        else if(number >= 13)
        {
            number = di[4]();
        }
        else
        {
            number = di[5]();
        }
    }
    return di[number];
}
