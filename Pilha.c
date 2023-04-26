#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel *next;
} Celula;
    
typedef struct {
    Celula *top;
} Pilha;
    
void criaPilha(Pilha *p) {
    p->top = NULL;
}

void push(Pilha *p, int value){
    Celula *new;
    new = malloc (sizeof(Celula));
    new->value = value;
    new->next = p->top;
    p->top = new;
}

void pop(Pilha *p){
    if(p->top == NULL){
        printf("Pilha vazia!!");
        return;
    }
    
    Celula *currentTop = p->top;
    p->top = currentTop->next;
    free(currentTop);
}

int peek(Pilha *p){
    
    if(p->top == NULL){
        printf("Nenhum elemento no topo!!");
        return -1;
    }
    
    return p->top->value;
}

void print(Pilha *p){
    Celula *current = p->top;
    while (current != NULL){
        printf("\n%d", current->value);
        current = current->next;
    }
    printf("\n");
}

void main()
{
    printf("Estrutura de dados - PILHA\n\n");
    Pilha pilha;
    criaPilha(&pilha);
    push(&pilha, 4);
    push(&pilha, 7);
    push(&pilha, 2);
    push(&pilha, 23);
    push(&pilha, 10);
    printf("Pilha antes da remoção:");
    print(&pilha);
    printf("Valor no topo da pilha: %d\n", peek(&pilha));
    pop(&pilha);
    pop(&pilha);
    printf("\nPilha após remover 2 valores:");
    print(&pilha);
    printf("Valor no topo da pilha: %d", peek(&pilha));
}