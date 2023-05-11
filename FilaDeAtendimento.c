#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

typedef struct celula {
    int value;
    struct celula *next;
} Celula;

typedef struct fila {
    Celula *first;
    Celula *last;
} Fila;

void criaFila(Fila *fila){
    fila->first = NULL;
    fila->last = NULL;
}

void enfileirar(Fila *fila){
    Celula *new = malloc(sizeof(Celula));
    int random = 10 + rand() % (100 - 10 + 1);
    printw("\nSenha gerada: %d", random);
    new->value = random;
    new->next = NULL;
    
    if (fila->first == NULL) {
        fila->first = new;
        fila->last = new;
    } else {
        fila->last->next = new;
        fila->last = new;
    }
}

int desenfileirar(Fila *fila) {
    if (fila->first == NULL) {
        printw("\nA fila esta vazia.");
        return 0;
    } else {
        Celula *temp = fila->first;
        int value = temp->value;
        
        fila->first = temp->next;
        
        if (fila->first == NULL) {
            fila->last = NULL;
        }
        
        free(temp);
        printw("\nCliente chamado: %d", value);
        return value;
    }
}

void print(Fila *fila) {
    Celula *current = fila->first;
    printw("\nFila de atendimento:");
    while (current != NULL) {
        printw("\n%d", current->value);
        current = current->next;
    }
}

void exibirMenu() {
    printw("\n1 - Gerar senha");
    printw("\n2 - Chamar cliente");
    printw("\n3 - Mostrar fila de atendimento");
    printw("\nOu pressione 'x' para sair");
}

void main(){
    Fila fila;
    criaFila(&fila);
    srand(time(NULL));
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    
    printw("Estrutura de dados - Fila de atendimento\n");

    exibirMenu();

    int key = getch();
    
    while(key != 'x'){
        switch(key){
            case '1': {
                clear();
                printw("\nEstrutura de dados - Fila de atendimento\n");
                enfileirar(&fila);
                printw("\n");
                print(&fila);
                printw("\n");
                exibirMenu();
                break;
            }
            case '2': {
                clear();
                printw("\nEstrutura de dados - Fila de atendimento\n");
                desenfileirar(&fila);
                printw("\n");
                print(&fila);
                printw("\n");
                exibirMenu();
                break;
            }
            case '3': {
                clear();
                printw("\nEstrutura de dados - Fila de atendimento\n");
                print(&fila);
                printw("\n");
                exibirMenu();
                break;
            }
            default:
                printw("\nEstrutura de dados - Fila de atendimento\n");
                printw("Opção inválida");
                exibirMenu();
                break;
        }
        key = getch();
    }
    endwin();
}