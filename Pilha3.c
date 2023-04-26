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
    printf("Valor removido do topo: %d\n", value);
    return value;
}

int top(Celula *p){
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
    Celula *p = malloc (sizeof(Celula));
    printf("PILHA");
    empilha(p, 8);
    empilha(p, 12);
    empilha(p, 1);
    empilha(p, 33);
    print(p);
    printf("Valor no topo: %d \n", top(p));
    desempilha(p);
    printf("PILHA APÓS REMOÇÃO");
    print(p);
    printf("Valor no topo: %d", top(p));
}