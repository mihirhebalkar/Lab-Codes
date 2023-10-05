//Mihir Hebalkar PRN: 2207122120

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct node *newNode =(struct node *) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;


    if(front == NULL && rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    struct node *temp;

    if(front == NULL)
         printf("Queue is Empty.\n");
    else
    {
        temp = front;
        int tempdata=front ->data;
        front = front->next;


        if(front == NULL)
            rear = NULL;

       free(temp);
       return tempdata;
    }

}

void search(int n)
{
	struct node *temp = front;
	int c=0,i=1;
	if(front==NULL)
	{
		printf("List is empty");
	}
	else{
		while(temp!=NULL)
		{
			if(temp->data==n){
				printf("\nFound at %d position",i);
				c=1;
				break;
			}
			temp=temp->next;
			i++;
		}
	}
	if(c==0){
		printf("\nElement not found!");
	}
}

void printList()
{
    struct node *temp = front;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    int z=dequeue();
    printf("%d is deleted", z);
    return 0;
}
