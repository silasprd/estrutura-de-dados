#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

typedef struct cel {
    char link[100];
    struct cel *next;
} Celula;

void empilha(Celula *p, char link[]){
    Celula *new = malloc (sizeof(Celula));
    //new->link = link;
    strcpy(new->link, link);
    new->next = p->next;
    p->next = new;
}

char* desempilha(Celula *p) {
    Celula *temp = p->next;
    char* value = malloc((strlen(temp->link) + 1) * sizeof(char));
    strcpy(value, temp->link);
    p->next = temp->next;
    free(temp);
    printw("\nLink desempilhado: %s", value);
    return value;
}

char* topo(Celula *p) {
    char* value = malloc((strlen(p->next->link) + 1) * sizeof(char));
    strcpy(value, p->next->link);
    printw("\nLink atual: %s", value);
    return value;
}

void print(Celula *p){
    Celula *new = p->next;
    printw("Histórico de navegação: ");
    while(new != NULL){
        printw("\n%s", new->link);
        new = new->next;
    }
    printw("\n");
}

void showOptions(){
    printw("\n1 - Navegar (empilha)");
    printw("\n2 - Voltar (desempilha)");
    printw("\n3 - Exibir link atual (topo)");
    printw("\n4 - Exibir links navegados (pilha)");
    printw("\nOu pressiona 'x' para sair");
}

int main()
{
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    printw("Estrutura de dados - PILHA\n");
    
    showOptions();
    
    int key = getch();
    
    Celula *p = malloc(sizeof(Celula));
    
    while(key != 'x') {
        
        switch(key){
            case '1':
                clear();
                showOptions();
                printw("\nDigite o link para navegar: ");
                refresh();
                char input[100];
                getstr(input);
                empilha(p, input);   
                break;
            case '2':
                clear();
                showOptions();
                desempilha(p);
                break;
            case '3':
                clear();
                printw("\n");
                topo(p);
                printw("\n");
                showOptions();
                break;
            case '4':
                clear();
                printw("\n");
                print(p);
                printw("\n");
                showOptions();
        }
        
        key = getch();
    }

    return 0;
    
}