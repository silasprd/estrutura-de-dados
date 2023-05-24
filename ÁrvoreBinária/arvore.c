#include <stdio.h>
#include <stdlib.h>

struct cel {
    int content;
    struct cel *left;
    struct cel *right;
};

typedef struct cel node;

typedef node *tree;

tree insert(node *r, int value){
    node *f, *p;
    if(r == NULL){
        return r;
    }
    
    f = r;
    
    while (f != NULL){
        p = f;
        if(value < f->content){
            f = f->left;
        } else {
            f = f->right;
        }
    }
    
    if(p->content > value){
        p->left->content = value;
    } else {
        p->right->content = value;
    }
    
    return r;
}

void print(node *r){
    if(r != NULL){
        print(r->left);
        printf("%d", r->content);
        print(r->right);
    }
}

int main()
{
    printf("Hello World");

    node *new = malloc (sizeof(node));
    
    insert(new, 8);
    insert(new, 5);
    insert(new, 10);
    
    return 0;
}
