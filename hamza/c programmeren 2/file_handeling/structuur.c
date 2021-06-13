#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data[10];
    struct node *next;
}*head[5];


void create(int count);
void print(int count);
int main()
{
    int i,n;
    n=5;  /*n is the total number of nodes */
	int a = 0;
	
	while(a < 2){			//ik heb dit gewoon geloopt om te zien als het gaat
		for(i=0;i<n;i++)
		{
			head[i]=NULL;
			create(i);
			print(i);
			printf("\n\n");
		}
	a++;
	}
	
	printf("hier kan ik wel printen :%s",head[2]->data);
    return 0;
}
void create(int count)
{
      int n2=5;  /*n2 is the number of nodes in a single linked list*/
	  printf("de count is %d\n",count);
      int j;
      struct node *temp;
      for(j=0;j<5;j++)
      {
             if(head[count]==NULL)
             {
                 temp=(struct node*)malloc(sizeof(struct node));
                 strcpy(temp->data,"wafels");
                 temp->next=NULL;
                 head[count]=temp;
             }
             else
             {
                temp->next=(struct node*)malloc(sizeof(struct node));
                 temp=temp->next;
                 strcpy(temp->data,"lekker");
                 temp->next=NULL;
             }
     }
}
void print(int count)
{
     struct node *temp;
     temp=head[count];
     while(temp!=NULL)
     {
          printf("%s->",temp->data);
          temp=temp->next;
     }
}