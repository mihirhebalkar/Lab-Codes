#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Underflow");
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

 
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}
//insert node at any position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Position not found\n");
        return;
    }
    if (position == 0 || *head == NULL) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int currentPosition = 0;
    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteLastNode(struct Node** head)
{
    if(*head==NULL)
    {
        printf("List is empty.Nothing to delete.\n");
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    } 
    else {
        
        *head = NULL;
    }
    free(current);
}

void deleteAtPosition(struct Node** head, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0 || *head == NULL) {
        printf("Invalid position or empty list\n");
        return;
    }
    struct Node* current = *head;
    int currentPosition = 0;
    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

void concat(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else if (*head2 != NULL) {
        struct Node* current = *head1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *head2;
        (*head2)->prev = current;
    }
}

void reverse(struct Node **head) {
    struct Node *current = *head;
    struct Node *temp = NULL;
    
    while (current != NULL) {
     
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}


void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}


void search(struct Node* head, int value) {
    struct Node* current = head;
    int pos=1;
    while (current != NULL) {
        if (current->data == value){
            printf("%d found at %d position\n",value,pos);
            break;
        }
        current = current->next;
        pos++;
    }
}

int ispresent(struct Node **head, int target)
{
    struct Node *temp=*head;
    
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    
    int temp;
    insertAtEnd(&head1, 10);
    insertAtEnd(&head1, 20);
    insertAtEnd(&head1, 30);
    insertAtEnd(&head1, 40);
    insertAtEnd(&head1, 50);
    
    insertAtEnd(&head2, 10);
    insertAtEnd(&head2, 200);
    insertAtEnd(&head2, 30);
    printf("First Linked List: ");
    display(head1);
    printf("\n");
    search(head1,30);
    printf("\nSecond Linked List: ");
    display(head2);
    printf("\n");
    concat(&head1,&head2);
    printf("\nConactenated Linked List : ");
    display(head1);
    printf("\n");
    reverse(&head1);
    printf("\nReversed Linked List: ");
    display(head1);
    
    printf("\n");
   

    
    return 0;
}

