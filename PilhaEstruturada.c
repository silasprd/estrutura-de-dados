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

void empilha(Pilha *p, int value){
    Celula *new;
    new = malloc (sizeof(Celula));
    new->value = value;
    new->next = p->top;
    p->top = new;
}

int desempilha(Pilha *p){
    if(p->top == NULL){
        printf("Pilha vazia!!");
        return 0;
    }
    
    Celula *nova = p->top;
    int value = nova->value;
    p->top = nova->next;
    free(nova);

    return value;
}

int topo(Pilha *p){
    
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
    
    empilha(&pilha, 10);
    empilha(&pilha, 200);
    empilha(&pilha, 3000);
    empilha(&pilha, 4000);
    
    printf("Valor no topo da pilha: %d\n", topo(&pilha));
    printf("Pilha antes da remoção:");
    print(&pilha);
    
    desempilha(&pilha);
    desempilha(&pilha);
    
    printf("\nValor no topo da pilha após remoção: %d", topo(&pilha));
    printf("\nPilha após remover 2 valores:");
    print(&pilha);
}