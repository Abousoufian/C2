#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d4() {return( ( rand() % 4 ) + 1 ); }
int d6() {return( ( rand() % 6 ) + 1 ); }
int d8() {return( ( rand() % 8 ) + 1 ); }
int d10() {return( ( rand() % 10 ) + 1 ); }
int d12() {return( ( rand() % 12 ) + 1 ); }
int d20() {return( ( rand() % 20 ) + 1 ); }


int throwDices(int (*dices[])(),int count,int *d) //inlezing van dices via main functie en verder gebruik voor de variable d
{
    for(int i = 0; i < count; i++)
    {
        d[i] = dices[i]();
    }
    return 0;
}

int main()
{
    int (*dices[])() = {&d4,&d6,&d8,&d10,&d10,&d12,&d20};
    int d[7];
    srand(time(NULL));
    throwDices(dices,6, d);
    for(int i= 0; i<6; i++)
    {
        printf("worp nr %d: %d\n",i+1,d[i]);
    }
    return 0;
}
