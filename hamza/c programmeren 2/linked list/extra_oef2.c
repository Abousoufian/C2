#include <stdio.h>
#include <stdlib.h>
//https://www.zentut.com/c-tutorial/c-stack-using-pointers/ uitleg

//maakt linked list en sorteerd op grootte
struct node{
	int data;
	struct node* next;
};

void init(struct node* head){
	head = NULL;
}

struct node* push(struct node* head, int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));//create new node
	if (temp == NULL){
		return 0;
	}
	temp->data = data;//put the data in the node
	temp->next = head;//connect node by pushing head away and pointing towords it and now new node is "head"
	head = temp;
	return head;
}

//voor te bubble sorten
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main(){
	
	struct node* head = NULL;
    int size, element;
    int counter = 0;
	struct node *current;
	struct node *test;
	
	
	//bepaalt grote linked list
    printf("Enter the number of stack elements:");
    scanf("%d",&size);
 
    printf("--- Push elements into the linked stack ---\n");
 
    init(head);
	
	//blijft nieuwe nodes maken totdat de size bereikt is
    while(counter < size)
    {
        printf("Enter a number to push into the stack:");
        scanf("%d",&element);
        head = push(head,element);
        counter++;
    }
    
	
	current = head;
	
	if(current != NULL){
		printf("stack: ");
		do{
			printf("-|%d|-",current->data);
			current = current->next;
		}while(current != NULL);
		
		printf("\n");
	}
	
	
	int tijdelijk[size];
	
	test = head;
	for(int x = 0; x < size; x++){
		tijdelijk[x] = test->data;
		test = test->next;
	}
	
	for(int x = 0; x < size-1; x++){
		for(int y = 0; y < size-1-x; y++){
			if(tijdelijk[y] > tijdelijk[y+1]){
				swap(&tijdelijk[y],&tijdelijk[y+1]);
			}
		}
		
	}
	
	for(int a = 0; a < size; a++){
		printf("%-|%d|-",tijdelijk[a]);
	}
	
	
	
	return 0;
}