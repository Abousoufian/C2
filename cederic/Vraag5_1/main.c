#include <stdio.h>
#include <stdlib.h>

#define BESTAND "D:\\Nijssen_Cederic\\OneDrive - PXL\\eerste jaar\\sem2\\c-programeren\\programma's\\Vraag5_1\\main.c"

int main()
{
    char buffer[110] = {0};
    FILE *fl = NULL;

    fl = fopen(BESTAND,"r");

    if(fl == NULL)
    {
        printf("ERROR");
        exit (EXIT_FAILURE);
    }

    while(feof(fl) == 0)
    {
        fgets(buffer, 110, fl);
        printf("%s",buffer);

    }
    fclose(fl);
    return 0;
}
