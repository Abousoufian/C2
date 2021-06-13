#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define AANTAL_PUNTEN 100

struct punt
{
	int x; 
	int y;
	struct punt* next;
};

//void printLijst(struct punt tekening);

void main( void )
{
	int aantalPunten = 0;
	
	//vraag gebruiken hoebeel punten hij wil ingeven.
	printf("Geef het aantal punten in: ");
	scanf("%d", &aantalPunten);
	
				/*
				//test: print opgeslagen waardes uit
				printf( "aantalpunten: %d", aantalPunten);
				*/
	
	struct punt tekening[AANTAL_PUNTEN];
	
	for(int i = 0; i<aantalPunten; ++i)
	{
		printf( "Coordinaat %d van x = ", i+1 );
		scanf( "%d", &tekening[i].x);
		
		printf( "Coordinaat %d van y = ", i+1 );
		scanf( "%d", &tekening[i].y);

		tekening[i].next= &tekening[i+1];
	}
				/*
				//test: print opgeslagen waardes uit
				for(int i = 0; i<aantalPunten; ++i)
				{
					printf( "Coordinaat %d van x = %d\n", i+1, tekening[i].x);
					printf( "Coordinaat %d van y = %d\n ", i+1, tekening[i].y);
				}
				*/
	// sorteert enkel op X-coordinaten			
	for(int i=0; i<aantalPunten-1; i++)
	{
		for(int j=1; j<aantalPunten; j++)
		{
			if(tekening[i].x < tekening[j].x)
			{
				//doet niks
			}
			else
			{
				int tempX=tekening[i].x;
				int tempY=tekening[i].y;
				
				tekening[i].x = tekening[j].x;
				tekening[j].x = tempX;
				
				tekening[i].y = tekening[j].y;
				tekening[j].y = tempY;
			}	
		}
	}
	
	// sorteert enkel op y-coordinaten
	for(int i=0; i<aantalPunten-1; i++)
	{
		for(int j=1; j<aantalPunten; j++)
		{
			if(tekening[i].x == tekening[j].x)
			{
				if(tekening[i].y < tekening[j].y)
				{
					//doet niks
				}
				else
				{
					int tempX=tekening[i].x;
					int tempY=tekening[i].y;
					
					tekening[i].x = tekening[j].x;
					tekening[j].x = tempX;
					
					tekening[i].y = tekening[j].y;
					tekening[j].y = tempY;
				}
			}
			else
			{
				//doet niks
			}	
		}	
	}					/*
						//test: print gesorteerde waardes uit
						for(int i = 0; i<aantalPunten; ++i)
						{
							printf( "Coordinaat %d van x = %d\n", i+1, tekening[i].x);
							printf( "Coordinaat %d van y = %d\n ", i+1, tekening[i].y);
						}
						*/
	
	double straal = 0.0;
	printf("Geef de straal in: ");
	scanf( "%lf", &straal);
	double vierkantswortel = 0.0;
	int deletedCoordinaten = 0;
	
	struct punt deletedList[AANTAL_PUNTEN];
	
	for(int i=0; i<aantalPunten; i++)
	{
		vierkantswortel = sqrt((tekening[i].x * tekening[i].x) + (tekening[i].y * tekening[i].y));
		//printf("%.2lf\n", vierkantswortel);
			
		
		if(vierkantswortel<straal)
		{
			deletedList[i].x = tekening[i].x;
			deletedList[i].y = tekening[i].y;
		}
		else
		{
			deletedCoordinaten++;
		}
	}
						/*
						//test: print deletedList uit
						for(int i = 0; i<(aantalPunten - deletedCoordinaten); ++i)
						{
							printf( "Coordinaat %d van x = %d\n", i+1, deletedList[i].x);
							printf( "Coordinaat %d van y = %d\n ", i+1, deletedList[i].y);
						}
						*/
} 





/*
void printLijst(struct punt tekening)
{
	for(int i = 0; i<aantalPunten; ++i)
	{
		printf( "Coordinaat %d van x = %d\n", i+1, tekening[i].x);
		printf( "Coordinaat %d van y = %d\n ", i+1, tekening[i].y);
	}
}
*/