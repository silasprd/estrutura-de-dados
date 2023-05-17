#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

typedef struct celula {
    int value;
    struct celula *next;
} Celula;

void enfileirar(Celula **start, Celula **end){
    Celula *new = malloc(sizeof(Celula));
    int random = 10 + rand() % (100 - 10 + 1);
    printw("\nSenha gerada: %d", random);
    new->value = random;
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
        printw("\nA fila esta vazia.");
        return 0;
    } else {
        Celula *temp = *start;
        int value = temp->value;
        
        *start = temp->next;
        
        if (*start == NULL) {
            *end = NULL;
        }
        
        free(temp);
        printw("\nCliente chamado: %d", value);
        return value;
    }
}

void print(Celula **start) {
    Celula *current = *start;
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
    Celula *start = NULL;
    Celula *end = NULL;
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
                enfileirar(&start, &end);
                printw("\n");
                print(&start);
                printw("\n");
                exibirMenu();
                break;
            }
            case '2': {
                clear();
                printw("\nEstrutura de dados - Fila de atendimento\n");
                desenfileirar(&start, &end);
                printw("\n");
                print(&start);
                printw("\n");
                exibirMenu();
                break;
            }
            case '3': {
                clear();
                printw("\nEstrutura de dados - Fila de atendimento\n");
                print(&start);
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