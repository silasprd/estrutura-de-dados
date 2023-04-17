#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int value;
    struct cel *next;
} Celula;

Celula head;
Celula *p;
p = &head;
p->next = NULL;

void push(Celula *p, int value){
    Celula *new = malloc (sizeof(Celula));
}

void main()
{

    
};