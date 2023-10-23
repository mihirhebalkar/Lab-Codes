#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf(" (head)\n");
}

Node* insertBeginning(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    newNode->next = head;
    last->next = newNode;
    return newNode;
}

Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    newNode->next = head;
    last->next = newNode;
    return head;
}

Node* insertAfter(Node* head, int data, int key) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* current = head;
    do {
        if (current->data == key) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    } while (current != head);

    printf("Key not found. Insertion failed.\n");
    free(newNode);
    return head;
}

Node* deleteBeginning(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    Node* temp = head;
    head = head->next;
    last->next = head;
    free(temp);
    return head;
}

Node* deleteEnd(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    prev->next = head;
    free(current);
    return head;
}

Node* deleteNodeByKey(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->data == key) {
        return deleteBeginning(head);
    }

    Node* current = head;
    Node* prev = NULL;

    do {
        if (current->data == key) {
            prev->next = current->next;
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    printf("Key not found. Deletion failed.\n");
    return head;
}

Node* reverseList(Node* head) {
    if (head == NULL) return NULL;

    Node* prev = NULL;
    Node* current = head;
    Node* nextNode;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    head->next = prev;

    return prev;
}

Node* concatenateLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node* list1Last = list1;
    while (list1Last->next != list1) {
        list1Last = list1Last->next;
    }

    Node* list2Last = list2;
    while (list2Last->next != list2) {
        list2Last = list2Last->next;
    }

    list1Last->next = list2;
    list2Last->next = list1;

    return list1;
}

int main() {
    Node* list = NULL;
    Node* list2 = NULL;

    int choice, data, key;

    while (1) {
        printf("\n--- Circular Linked List Operations Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Key\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Key\n");
        printf("7. Reverse List\n");
        printf("8. Concatenate Lists\n");
        printf("9. Display List\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                list = insertBeginning(list, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                list = insertEnd(list, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                list = insertAfter(list, data, key);
                break;
            case 4:
                list = deleteBeginning(list);
                break;
            case 5:
                list = deleteEnd(list);
                break;
            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                list = deleteNodeByKey(list, key);
                break;
            case 7:
                list = reverseList(list);
                break;
            case 8:
                list2 = insertEnd(list2, 100); 
                list2 = insertEnd(list2, 200);
                list = concatenateLists(list, list2);
                break;
            case 9:
                displayList(list);
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


