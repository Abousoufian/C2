#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int number1 = 0;
    int number2 = 0;
    int *pointer1 = 0;
    int *pointer2 = 0;
    char input[1000] = {0};

    for(int i = 0; i<2; i++)
    {
        printf("geef getal %d in: ", i+1);
        gets(input);
        if(i == 0)
        {
            number1 = atoi(input);
        }
        else
        {
            number2 = atoi(input);
        }
    }
    pointer1 = &number1;
    pointer2 = &number2;
    printf("nummer 1 is %d dit is opgeslagen op %p in %d\nnummer 2: %d dit is opgeslagen op %p in %d\n", *pointer1, pointer1, pointer1, *pointer2, pointer2, pointer2);
}

