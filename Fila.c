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

void criaFila(Fila *fila) {
    fila->first = NULL;
    fila->last = NULL;
}

void enfileirar(Fila *fila) {
    Celula *new = (Celula*) malloc(sizeof(Celula));
    int random = 10 + rand() % (100 - 10 + 1);
    printw("\n%d", random);
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
        printw("A fila esta vazia.\n");
        return 0;
    } else {
        Celula *temp = fila->first;
        int value = temp->value;
        
        fila->first = temp->next;
        
        if (fila->first == NULL) {
            fila->last = NULL;
        }
        
        free(temp);
        return value;
    }
}

void print(Fila *fila) {
    Celula *current = fila->first;

    while (current != NULL) {
        printw("\n%d", current->value);
        current = current->next;
    }
}

void exibirMenu() {
    printw("\n");
    printw("\n1 - Gerar senha");
    printw("\n2 - Chamar cliente");
    printw("\n3 - Mostrar fila de atendimento");
    printw("\nOu pressione 'x' para sair");
}

void main() {
    Fila fila;
    criaFila(&fila);
    srand(time(NULL));
    initscr();
    cbreak();
    //noecho();
    keypad(stdscr, TRUE);

    exibirMenu();

    int key = getch();


    while (key != 'x') {
        switch(key){
            case '1': {
                clear();
                printw("Senha gerada: ");
                enfileirar(&fila);
                exibirMenu();
                break;
            }
            case '2': {
                clear();
                printw("Cliente chamado:\n%d", desenfileirar(&fila));
                exibirMenu();
                break;
            }
            case '3': {
                clear();
                printw("Fila de atendimento:");
                print(&fila);
                exibirMenu();
                break;
            }
            default:
                printw("Opção inválida");
                exibirMenu();
                break;
        }
        key = getch();
    }   
    endwin();
    
}