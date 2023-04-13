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
    if(isEmpty(stack)){
        printf("Pilha vazia!!! \n");
        return;
    }
    for(int i = stack->size; i > 0; i--){
        printf("%d\n", stack->top[i]);
    }
};

void main()
{
    printf("Estrutura de dados - PILHA \n");
    Stack stack;
    createStack(&stack);
    push(&stack, 8);
    push(&stack, 10);
    push(&stack, 4);
    push(&stack, 7);
    printf("\nPilha:\n");
    print(&stack);
    pop(&stack);
    pop(&stack);
    printf("\nPilha após remoção: \n");
    print(&stack);
    printf("\nTopo da pilha: \n");
    printf("%d \n", peek(&stack));
    printf("\nTamanho da pilha: \n");
    printf("%d", size(&stack));
    
};