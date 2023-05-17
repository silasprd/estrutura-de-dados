#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel *next;
} Celula;

void empilha(Celula *p, int value){
    Celula *new = malloc (sizeof(Celula));
    new->value = value;
    new->next = p->next;
    p->next = new;
}

int desempilha(Celula *p){
    Celula *new = p->next;
    int value = new->value;
    p->next = new->next;
    free(new);
    return value;
}

int topo(Celula *p){
    return p->next->value;
}

void print(Celula *p){
    Celula *new = p->next;
    while(new != NULL){
        printf("\n%d", new->value);
        new = new->next;
    }
    printf("\n");
}

void main()
{
    printf("Estrutura de dados - PILHA");

    Celula *p = malloc (sizeof(Celula));
    p = NULL;

    empilha(p, 10);
    empilha(p, 200);
    empilha(p, 3000);
    empilha(p, 40000);

    printf("\nValor no topo da pilha: %d \n", topo(p));
    printf("Pilha antes da remoção:");
    print(p);

    desempilha(p);
    
    printf("\nValor no topo da pilha após remoção: %d \n", topo(p));
    printf("Pilha após remoção:");
    print(p);
}