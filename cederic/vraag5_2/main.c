#include <stdio.h>
#include <stdlib.h>

#define BESTAND "D:\\Nijssen_Cederic\\OneDrive - PXL\\eerste jaar\\sem2\\c-programeren\\programma's\\vraag5_2\\print_Hello_World.c"

int main()
{
    FILE *fl = NULL;

    fl = fopen(BESTAND, "w");
    if (fl ==NULL)
    {
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    fprintf(fl,"#include <stdio.h>\n\nint main()\n{\n \tprintf(\"Hello World\");\n\treturn 0;\n}");
    fclose(fl);
    printf("Klaar\n");
    return 0;
}
