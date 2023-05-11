#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int value;
    struct celula *next;
} Celula;

typedef struct fila {
    Celula *start;
    Celula *end;
} Fila;

void criaFila(Fila *fila) {
    fila->start = NULL;
    fila->end = NULL;
}

void enfileirar(Fila *fila, int value) {
    Celula *new = (Celula*) malloc(sizeof(Celula));
    new->value = value;
    new->next = NULL;
    
    if (fila->start == NULL) {
        fila->start = new;
        fila->end = new;
    } else {
        fila->end->next = new;
        fila->end = new;
    }
}

int desenfileirar(Fila *fila) {
    if (fila->start == NULL) {
        printf("A fila esta vazia.\n");
        return 0;
    } else {
        Celula *removed = fila->start;
        int value = removed->value;

        
        
        fila->start = removed->next;
        
        if (fila->start == NULL) {
            fila->end = NULL;
        }
        
        free(removed);
        return value;
    }
}

void print(Fila *fila) {
    Celula *current = fila->start;

    while (current != NULL) {
        printf("\n %d", current->value);
        current = current->next;
    }
    printf("\n");
}

void main() {
    Fila fila;
    criaFila(&fila);
    
    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    enfileirar(&fila, 40);
    enfileirar(&fila, 50);
    
    printf("Fila antes da remoção: ");
    print(&fila);
    
    int value = desenfileirar(&fila);
    printf("\nValor removido da fila: %d\n", value);
    printf("Fila após remoção: ");
    print(&fila);
    
}