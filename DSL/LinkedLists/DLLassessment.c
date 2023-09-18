#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    int data;
    struct node *prev;
};

void insertatend(struct node **head, int data);
void insertafterpos(struct node **head, int data,int pos);
int largest(struct node *head);
void sort(struct node *head);
void traverse(struct node **head);


int main()
{
	int z;
	
    struct node *head=NULL;
    insertatend(&head,45);
    insertatend(&head,92);
    insertatend(&head,46);
    insertatend(&head,3);
    traverse(&head);
    
    z=largest(head);
    printf("\n\nLargest is: %d",z);
    sort(head);
    
    printf("\n\nSorted DLL ");
    traverse(&head);
    
    printf("\n\nAdding new node with 66 at sorted position");
    insertafterpos(&head,66,3);
    
    traverse(&head);
    return 0;
}

void traverse(struct node **head)
{
    struct node *temp=*head;
    printf("\nDLL : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;    
    }
}

void insertatend(struct node **head, int data)
{
    struct node *new;
    new=malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    struct node *temp=*head;
    
    if(*head==NULL)
    {
        new->prev=NULL;
        new->next=NULL;
        *head=new;
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=NULL;
        new->prev=temp;
    }
    
}

void insertafterpos(struct node **head, int data,int pos)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    struct node *temp=*head;
    struct node *temp2=NULL;
    int i=1;
    while(i!=pos)
    {
    	temp=temp->next;
    	i++;
    }
    temp2=temp->next;
    ptr->next=temp2;
    ptr->prev=temp;
    temp2->prev=ptr;
    temp->next=ptr;
}

int largest(struct node *head)
{
    struct node *curr=head;
    struct node *index=curr->next;
    int large = curr->data; 
    while(index != NULL)
    {
        if(index->data > large)
        {
            large = index->data;
        }
        index=index->next;
    }
    return large; 
}

void sort(struct node *head)
{
    struct node *current=head;
    
    
    struct node *index=NULL;
    
    while(current->next!=NULL)
    {
        index=current->next;
        while(index!=NULL)
        {
            if((current->data) > (index->data))
            {
                int temp=current->data;
                current->data=index->data;
                index->data=temp;
            }
            index=index->next;
        }
        current=current->next;
    }
}
