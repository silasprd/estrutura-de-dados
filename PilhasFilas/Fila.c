#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int value;
    struct celula *next;
} Celula;


void enfileirar(Celula **start, Celula **end, int value) {
    Celula *new = (Celula*) malloc(sizeof(Celula));
    new->value = value;
    new->next = NULL;
    
    if (*start == NULL) {
        *start = new;
        *end = new;
    } else {
        (*end)->next = new;
        *end = new;
    }
}

int desenfileirar(Celula **start, Celula **end) {
    if (*start == NULL) {
        printf("A fila esta vazia.\n");
        return 0;
    } else {
        Celula *removed = *start;
        int value = removed->value;
       
        *start = removed->next;
        
        if (*start == NULL) {
            *end = NULL;
        }
        
        free(removed);
        return value;
    }
}

void print(Celula **start) {
    Celula *current = *start;

    while (current != NULL) {
        printf("\n%d", current->value);
        current = current->next;
    }

    printf("\n");
}

void main() {
    Celula *start = NULL;
    Celula *end = NULL;

    
    enfileirar(&start, &end, 10);
    enfileirar(&start, &end, 20);  
    enfileirar(&start, &end, 30);  
    enfileirar(&start, &end, 40);
    
    printf("Fila:");

    print(&start);
    
    printf("Valor removido: %d\n", desenfileirar(&start, &end));
    
    printf("\nFila após remoção: ");
    
    print(&start);
}