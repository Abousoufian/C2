    #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d4(){printf("d4\n");return((rand()% 4)+1);}
int d6(){printf("d6\n");return((rand()% 6)+1);}
int d8(){printf("d8\n");return((rand()% 8)+1);}
int d10(){printf("d10\n");return((rand()% 10)+1);}
int d12(){printf("d12\n");return((rand()% 12)+1);}
int d20(){printf("d20\n");return((rand()% 20)+1);}

void trowDice (int (*d[])(), int *array);

int main()
{
    srand(time(NULL));
    int (*dice[])() = {&d4,&d6,&d8,&d10,&d12,&d20};
    int arr[6] = {0};

    trowDice(dice,arr);
    for(int i = 0; i<6; i++)
    {
     printf("worp %d: %d\n",i+1,arr[i]);
    }
}

void trowDice (int (*d[])(), int *array)
{
    for(int i = 0; i<6; i++)
    {
        array[i] = d[i]();
    }
}
