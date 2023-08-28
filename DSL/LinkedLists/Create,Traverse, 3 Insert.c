
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

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

void insertatBegin(struct node** head,int data)
{
	struct node *lk;

	lk=malloc(sizeof(struct node));
	
	lk->data=data;

	lk->next=*head;
	*head=lk;
}

void insertatEnd(struct node** head, int data) {
    struct node* lk = malloc(sizeof(struct node));
    lk->data = data;
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

void insert(struct node** head, int data,int pos)
{
	struct node* lk = malloc(sizeof(struct node));
	struct node* new = malloc(sizeof(struct node));
	lk=*head;
	new=*head;
	int i;
	for(i=0;i<pos-1;i++)
	{
		lk=lk->next;
	}
	for(i=0;i<pos;i++)
	{
		new=new->next;
	}
	lk->data=data;
	lk->next=new;
}


int main() {


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
    
	insertatBegin(&head,45);
	printf("\nAfter inserting at begin:\n");
    traverse(head);

    insertatEnd(&head,23);
    printf("\nAfter inserting at end:\n");
    traverse(head);
    
    insert(&head,0,3);
    printf("\nAfter inserting at 3rd position:\n");
    traverse(head);
    return 0;
    
    
}
