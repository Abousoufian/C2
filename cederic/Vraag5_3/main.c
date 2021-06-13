#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
#define BESTAND_INPUT "D:\\Nijssen_Cederic\\OneDrive - PXL\\eerste jaar\\sem2\\c-programeren\\programma's\\Vraag5_3\\input.txt"
#define BESTAND_OUTPUT "D:\\Nijssen_Cederic\\OneDrive - PXL\\eerste jaar\\sem2\\c-programeren\\programma's\\Vraag5_3\\output.txt"

struct crimereport{
    char dayTime[14];
    char address[40];
    char district;
    char beat[3];
    int grid;
    char crimedescr[40];
    int ucr_ncic_code;
    double latitude;
    double longitude;
};

int main()
{
    FILE *flIN = NULL;
    FILE *flOUT = NULL;
    int counter = 0;
    int lenght = 0;
    int index =0;
    int placehorlder = 0;
    double placeholderf = 0.0;
    char CaseState = 0;
    char line[MAX];
    char **lines;
    struct crimereport single;
    int CrimeCode = 0;

    flIN = fopen(BESTAND_INPUT, "r");
    flOUT = fopen(BESTAND_OUTPUT, "w");

    if(flIN == NULL)
    {
        perror("File input not found");
        exit(EXIT_FAILURE);
    }
    if(flOUT == NULL)
    {
        perror("File output not found");
        exit(EXIT_FAILURE);
    }

    while(feof(flIN) == 0)
    {
        fgets(line,MAX,flIN);
        counter ++;
    }

    rewind(flIN);
    lines = malloc(sizeof (char*) *counter);

    for(int i = 0; i<counter && feof(flIN) == 0; i++)
    {
        fgets(line,MAX,flIN);
        lenght = 0;
        for(int j = 0; line[j] !='\r';j++)
        {
            //printf("%d, ",j);
            lenght ++;
        }
        lines[i] = malloc(sizeof (char) *lenght);
        strncpy(lines[i],line,lenght);
        //printf("%s\n",lines[i]);
    }

    fclose(flIN);
    printf("file closed\n");
    //printf("%d\n",counter);

    printf("Op welke misdaad code wilt u zoeken? ");
    scanf(" %d",&CrimeCode);

    for(int i = 0; i<MAX; i++)
    {
        line[i] = 0;
    }

    for(int i = 0; i<counter; i++)
    {
        index = 0;
        for (int j = 0; j<MAX && lines[i][j] != '\0';j++)
        {

            if(lines[i][j] != ',')
            {
                line[index] = lines[i][j];
                //printf("%c",line[index]);
                index ++;
            }
            if(lines[i][j+1]==',' || lines[i][j+1]=='\0')
            {
                //printf("\n");
                index ++;
                //printf("%s, %d\n ",line,CaseState);
                switch (CaseState)
                {
                case 0:
                    strncpy(single.dayTime,line,index);
                    CaseState ++;
                    break;
                case 1:
                    strncpy(single.address,line,index);
                    CaseState ++;
                    break;
                case 2:
                    placehorlder = atoi(line);
                    single.district = placehorlder;
                    CaseState ++;
                    break;
                case 3:
                    strncpy(single.beat,line,2);
                    CaseState ++;
                    break;
                case 4:
                    placehorlder = atoi(line);
                    single.grid = placehorlder;
                    CaseState ++;
                    break;
                case 5:
                    strncpy(single.crimedescr,line,index);
                    CaseState ++;
                    break;
                case 6:
                    placehorlder = atoi(line);
                    single.ucr_ncic_code = placehorlder;
                    CaseState ++;
                    break;
                case 7:
                    placeholderf = atof(line);
                    single.latitude = placeholderf;
                    CaseState ++;
                    break;
                case 8:
                    placeholderf = atof(line);
                    single.longitude = placeholderf;
                    CaseState = 0;
                    break;
                default:
                    perror("INVALLIT CASESTATE");
                    exit(EXIT_FAILURE);
                    break;
                }
                index = 0;
                for(int i = 0; i<MAX; i++)
                {
                    line[i] = 0;
                }
            }
        }
        //printf("%s, %s, %d, %s, %d, %s, %d, %.8lf, %.7lf\n",single.dayTime, single.address, single.district, single.beat, single.grid, single.crimedescr, single.ucr_ncic_code, single.latitude, single.longitude);
        //printf("%s",lines[i]);
        //gets(test);
        if(single.ucr_ncic_code == CrimeCode)
        {
            fprintf(flOUT,"%s, %s, %d, %s, %d, %s, %d, %.8lf, %.7lf\n",single.dayTime, single.address, single.district, single.beat, single.grid, single.crimedescr, single.ucr_ncic_code, single.latitude, single.longitude);
        }
    }

    printf("Output file gemaakt in: "BESTAND_OUTPUT"\n");

    for (int i = 0; i<counter; i++)
    {
        free(lines[i]);
    }
    free(lines);


    return 0;
}
