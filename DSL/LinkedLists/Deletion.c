#include<stdio.h>
#include<stdlib.h>
//Delete

struct node{
    int data;
    struct node *next;
};


int main()
{
    struct node *head,*first,*second;
    
	head=malloc(sizeof(struct node));
    first=malloc(sizeof(struct node));
    second=malloc(sizeof(struct node));
    
	head->data=5;
    first->data=95;
    second->data=48;
    
	head->next=first;
    first->next=second;
    second->next=NULL;	
    
	traverse(head);
    
	deleteatbegin(&head);
	printf("\nAfter deleting at begin:\n");
    traverse(head);
    
    void deleteatend(&head);
	printf("\nAfter deleting at end:\n");
    traverse(head);
    
}

void traverse(struct node *head)
{
	int count=0;
	struct node *ptr;
	ptr=head;
	printf("Values : ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		count++;
		ptr=ptr->next;
	}
	printf("\nCount = %d",count);
}

void deleteatbegin(struct node** head) {
   struct node* ptr = *head;
   *head = (*head)->next; 
   free(ptr); 
}

void deleteatEnd(struct node** head){
	struct node *new = *head;
	
}

void deleteatend(struct node **head){
	struct node* lk = malloc(sizeof(struct node));
    lk->next = NULL;  

    if (*head==NULL) {
        *head = lk;
        return;
    }
    struct node *linkedlist = *head;
    while (linkedlist->next != NULL)
        linkedlist = linkedlist->next;

    linkedlist->next = lk;
}
