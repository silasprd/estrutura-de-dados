#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *top;
} Stack;

//criar pilha
void createStack(Stack *stack) {
    stack->size = 0;
    stack->top = (int *)malloc(sizeof(int));
};

//verificar se a pilha está vazia
int isEmpty(Stack *stack){
    return stack->size == 0;  
};

//adicionar elemento na pilha
void push(Stack *stack, int value){
    stack->top[++stack->size] = value;
};

//remover elemento na pilha
void pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Pilha vazia, não é possível remover!!!");
        return;
    }
    stack->top[--stack->size];
};

//retornar elemento no topo da pilha
int peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Pilha vazia, nenhum elemento no topo!!!");
        return -1;
    }
    return stack->top[stack->size];  
};

//retornar o tamanho da pilha
int size(Stack *stack) {
    return stack->size;
};

//imprimir a pilha
void print(Stack *stack){
    printf("\nStack:\n");
    if(isEmpty(stack)){
        printf("Pilha vazia!!!");
        return;
    }
    for(int i = stack->size; i > 0; i--){
        printf("%d\n", stack->top[i]);
    }
};

void main()
{
    printf("Hello World");
    Stack stack;
    createStack(&stack);
    push(&stack, 8);
    push(&stack, 10);
    push(&stack, 4);
    push(&stack, 7);
    pop(&stack);
    pop(&stack);
    print(&stack);
    printf("\nStack top: \n");
    printf("%d \n", peek(&stack));
    printf("\nStack size: \n");
    printf("%d", size(&stack));
    
};