#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;
    
typedef struct {
    Node* top;
} Stack;
    
void createStack(Stack* st) {
    st->top = NULL;
}

void push(Stack* st, int value){
    Node* new = (Node*) malloc(sizeof(Node));
    new->value = value;
    new->next = st->top;
    st->top = new;
}

void print(Stack* st){
    Node* current = st->top;
    while (current != NULL){
        printf("\n%d", current->value);
        current = current->next;
    }
    printf("\n");
}

void main()
{
    printf("Hello World");
    Stack stack;
    createStack(&stack);
    push(&stack, 4);
    push(&stack, 7);
    push(&stack, 2);
    print(&stack);
}
