#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula *proximo;
} Celula;

typedef struct fila {
    Celula *inicio;
    Celula *fim;
} Fila;

void inicializar_fila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enfileirar(Fila *fila, int valor) {
    Celula *nova_celula = (Celula*) malloc(sizeof(Celula));
    nova_celula->valor = valor;
    nova_celula->proximo = NULL;
    
    if (fila->inicio == NULL) {
        fila->inicio = nova_celula;
        fila->fim = nova_celula;
    } else {
        fila->fim->proximo = nova_celula;
        fila->fim = nova_celula;
    }
}

int desenfileirar(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A fila esta vazia.\n");
        return 0;
    } else {
        Celula *celula_removida = fila->inicio;
        int valor_removido = celula_removida->valor;
        
        fila->inicio = celula_removida->proximo;
        
        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
        
        free(celula_removida);
        return valor_removido;
    }
}

void exibir_fila(Fila *fila) {
    Celula *celula_atual = fila->inicio;
    
    printf("Fila: ");
    while (celula_atual != NULL) {
        printf("%d ", celula_atual->valor);
        celula_atual = celula_atual->proximo;
    }
    printf("\n");
}

void main() {
    Fila minha_fila;
    inicializar_fila(&minha_fila);
    
    enfileirar(&minha_fila, 10);
    enfileirar(&minha_fila, 20);
    enfileirar(&minha_fila, 30);
    
    exibir_fila(&minha_fila);
    
    int valor_removido = desenfileirar(&minha_fila);
    printf("Valor removido: %d\n", valor_removido);
    
    exibir_fila(&minha_fila);
    
}