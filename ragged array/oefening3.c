#include <stdio.h>

#define AANTAL 15

void getLatitude(char *nmea, char *latitude);

int main()
{
    char testData[] = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    char lat[AANTAL]={0};

    getLatitude(testData,lat);
    printf("de latitude is: %s\n",lat);
}

void getLatitude(char *nmea, char *latitude)
{
    int counter = 0;
    char commaPlaats[3] = {0};
    char plaatsTussenComma = 0;

    for(int i = 0; counter < 4 ;i++)
    {
        if(nmea[i] == ',')
        {
            commaPlaats[(int)counter] = i;
            counter ++;
        }
    }
    counter = 0;
    plaatsTussenComma = commaPlaats[2]-commaPlaats[1];
    while (counter < plaatsTussenComma)
    {
        latitude[counter] = nmea[counter+commaPlaats[1]];
        counter ++;
    }
    latitude[counter] = ',';
    latitude[counter+1] = nmea[commaPlaats[2]+1];
}