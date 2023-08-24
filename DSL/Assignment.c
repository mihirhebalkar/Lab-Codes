#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

void insert(struct ListNode** head, int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct ListNode* mergeLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;

    while (1) {
        if (list1 == NULL) {
            tail->next = list2;
            break;
        } else if (list2 == NULL) {
            tail->next = list1;
            break;
        }
        
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        
        tail = tail->next;
    }

    return dummy.next;
}

struct ListNode* binarySearch(struct ListNode* head, int key) {
    struct ListNode* left = head;
    struct ListNode* right = NULL;

    while (left != right) {
        struct ListNode* mid = left;
        int count = 0;
        while (mid != right) {
            mid = mid->next;
            count++;
        }

        mid = left;
        for (int i = 0; i < count / 2; i++) {
            mid = mid->next;
        }

        if (mid->data == key) {
            return mid;
        } else if (mid->data < key) {
            left = mid->next;
        } else {
            right = mid;
        }
    }

    return NULL;
}

int main() {
    struct ListNode* list1 = NULL;
    insert(&list1, 1);
    insert(&list1, 3);
    insert(&list1, 5);

    struct ListNode* list2 = NULL;
    insert(&list2, 2);
    insert(&list2, 4);
    insert(&list2, 6);

    struct ListNode* mergedList = mergeLists(list1, list2);

    // Perform binary search
    int key = 6;
    struct ListNode* result = binarySearch(mergedList, key);

    if (result != NULL) {
        printf("Key %d found in the merged linked list.\n", key);
    } else {
        printf("Key %d not found in the merged linked list.\n", key);
    }

    return 0;
}
