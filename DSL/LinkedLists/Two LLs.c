#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void insertb(struct node **head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    if (*head == NULL) {
        temp->next = NULL;
        temp->prev = NULL;
        *head=temp;
    } else {
        temp->next = *head;
        temp->prev = NULL;
        (*head)->prev = temp;
        *head = temp;
    }
}

void dele(struct node **head)
{
    struct node *temp = *head;
    if (temp == NULL)
    {
        printf("The list is empty");
    }
    if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}


void traverse(struct node **head) {
    struct node *temp = *head;
    printf("DLL : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int ispresent(struct node *head,int data)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==	data)
		{
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}


struct node *intersection(struct node *head,struct node *head2)
{
	struct node *result=NULL;
	struct node *temp=head;
	while(temp!=NULL)
	{
		if(ispresent(head2,temp->data)==1)
		{
			insertb(&result,temp->data);
		}
		temp=temp->next;
	}
	return result;
}

struct node *concat(struct node *head1, struct node *head2)
{
    struct node *temp;
    struct node *result = NULL;
    temp = head1;
    while (temp != NULL)
    {
        insertb(&result, temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL)
    {
        insertb(&result, temp->data);
        temp = temp->next;
    }
    return result;
}

void uniondll(struct node *head)
{
	struct node *t1, *t2, *dup;
	t1=head;
	
	while(t1!=NULL)
	{
		t2=t1;
		
		while(t2->next!=NULL)
		{
			if(t1->data==t2->next->data)
			{
				dup=t2->next;
				t2->next=t2->next->next;
				free(dup);
			}
			else
			{
				t2=t2->next;
			}
		}
		t1=t1->next;
	}
}

int main() {
    struct node *head, *head1,*in, *conct;
    head = NULL; // Initialize head to NULL
    head1 = NULL; // Initialize head1 to NULL
    in = NULL;
    conct=NULL;

    insertb(&head, 30);
    insertb(&head, 40);
    insertb(&head, 50);
    insertb(&head, 60);

    insertb(&head1, 60);
    insertb(&head1, 70);
    insertb(&head1, 80);
    insertb(&head1, 30);
    
    traverse(&head);
    traverse(&head1);
    
    in=intersection(head,head1);
    traverse(&in);
    
    conct=concat(head,head1);

    uniondll(conct);
    traverse(&conct);

    return 0;
}
