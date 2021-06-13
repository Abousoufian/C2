#include <stdio.h>
#include <stdlib.h>
//https://www.zentut.com/c-tutorial/c-stack-using-pointers/ uitleg


struct node{
	int data;
	struct node* next;
};


//initialise stack with NULL
void init(struct node* head){
	head = NULL;
}


//push element into stack (add)
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


//pop element from stack(remove)
struct node* pop(struct node *head, int *element){
	struct node* temp = head;
	*element = head->data;
	head = head->next;
	free(temp);
	return head;
}


//display linked list
void display(struct node* head){
	struct node *current;
	current = head;
	if(current != NULL){
		printf("stack: ");
		do{
			printf("|%d|",current->data);
			current = current->next;
		}while(current != NULL);
		
		printf("\n");
	}
	else{
		printf("stack is empty\n");
	}
}


//returns 1 if the stack is empty, otherwise returns 0
int empty(struct node* head)
{
    return head == NULL ? 1 : 0;
}


int main(){
	
    struct node* head = NULL;
    int size, element;
    int counter = 0;
	
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
        display(head);
        counter++;
    }
	
	counter = 0;
	size = 0;
	
	printf("Enter the number of elements you want to pop:");
    scanf("%d",&size);
	
	
    printf("--- Pop elements from the linked stack --- \n");
    while(empty(head) == 0 && counter < size)
    {
        head = pop(head,&element);
        printf("Pop %d from stack\n",element);
        display(head);
		counter++;
    }
	
	
	
	
	
	/*struct node* head = NULL; 
    struct node* second = NULL; 
    struct node* third = NULL; 
	
	head = (struct node*) malloc(sizeof(struct node));
	second = (struct node*) malloc(sizeof(struct node));
	third = (struct node*) malloc(sizeof(struct node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	while( head!= NULL){
		printf("%d\n",head->data);
		head = head->next;
	}
	while( head!= NULL){
		printf("%d\n",head->data);
		head = head->next;
	}*/
	
	return 0;
}