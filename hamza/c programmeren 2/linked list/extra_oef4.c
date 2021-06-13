#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                   
    struct node *next;       
}*stnode;

void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
 
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) 
    {
        printf(" Memory can not be allocated.");
    }
    else
    {

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode-> num = num;      
        stnode-> next = NULL; //Links the address field to NULL
        tmp = stnode;
 

        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
 

            if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->next = NULL; // links the address field of fnNode with NULL
                tmp->next = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->next;
            }
        }
    }
} 

void InsertatEnd(int num, int jumps)
{
    struct node *fnNode,*tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
		fnNode->num = num; //Links the data part
		for(int i = 0; i < jumps; i++){
			
			fnNode = fnNode->next; 
		}
		fnNode->next = fnNode;
    }
}

void displayList()
{
    struct node *tmp;
	printf("linked list is:");
    if(stnode == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf("-|%d|-", tmp->num);   // prints the data of current node
            tmp = tmp->next;                 // advances the position of current node
        }
    }
} 
 
 
int main()
{
    int n,num;
	int count = 0;
	struct node *temp;
	
	printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
	displayList();
	
	
	temp = stnode;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	printf("\n");
	printf("de count is %d\n",count);
	InsertatEnd(5,count);
	displayList();
	
	
	
    return 0;
}
