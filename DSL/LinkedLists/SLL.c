#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* current = head;

    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head) {
        newNode->next = head;
    }

    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (!head) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next) {
        current = current->next;
    }

    current->next = newNode;

    return head;
}

struct Node* insertAfter(struct Node* head, int data, int key) {
    struct Node* newNode = createNode(data);

    struct Node* current = head;

    while (current) {
        if (current->data == key) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

    printf("Key not found. Insertion failed.\n");
    free(newNode);
    return head;
}

struct Node* deleteBeginning(struct Node* head) {
    if (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct Node* deleteEnd(struct Node* head) {
    if (!head) {
        return NULL;
    }

    if (!head->next) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while (current->next->next) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return head;
}

struct Node* deleteNodeByKey(struct Node* head, int key) {
    if (!head) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;

    while (current->next) {
        if (current->next->data == key) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return head;
        }
        current = current->next;
    }

    printf("Key not found. Deletion failed.\n");
    return head;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode;

    while (current) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    struct Node* current = list1;

    while (current->next) {
        current = current->next;
    }

    current->next = list2;

    return list1;
}

int main() {
    struct Node* list = NULL;
    struct Node* list2 = NULL;

    int choice, data, key;

    while (1) {
        printf("\n--- Singly Linked List Operations Menu ---\n");
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


