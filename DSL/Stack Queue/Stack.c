#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct stack {
    int top;
    int items[MAX];
};

typedef struct stack st;
int count = 0;

void createEmptyStack(st *s) {
    s->top = -1;
}

void push(st *s, int new) {
    if (isfull(s)) {
        printf("stack is full");
    } else {
        s->top++;
        s->items[s->top] = new;
        count++;
    }
}

void pop(st *s) {
    if (isempty(s)) {
        printf("empty stack");
    } else {
        printf("item popped = %d", s->items[s->top]);
        s->top--;
        count--;
    }
}

void printStack(st *s) {
    for (int i = 0; i < count; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int isfull(st *s) {
    if (s->top == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isempty(st *s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int ch;
    st *s = malloc(sizeof(st));
    createEmptyStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    printStack(s);
    pop(s);
    printStack(s);

    free(s); 
    return 0;
}
