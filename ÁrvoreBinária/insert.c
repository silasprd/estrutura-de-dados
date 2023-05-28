#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node* insert(Node *root, int value){
    
    Node *f, *p;
    Node *new = malloc (sizeof(Node));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    
    if(root == NULL){
        return new;
    }
    
    f = root;
    
    while (f != NULL){
        
        p = f;
        
        if(f->value > new->value){
            f = f->left;
        } else {
            f = f->right;
        }
        
    }
    
    if(p->value > new->value){
        p->left = new;
    } else {
        p->right = new;
    }
    
    return root;
}

// void print(Node *root){
//     if(root != NULL){
//         print(root->left);
//         printf("%d ", root->value);
//         print(root->right);
//     }
// }

void printTreeStructure(Node* root, int space) {
    
    if (root == NULL) {
        return;
    }

    printTreeStructure(root->right, space + 1);

    for (int i = 0; i < space; i++) {
        printf("    ");
    }

    printf("%d\n", root->value);

    printTreeStructure(root->left, space + 1);
    
}

int main()
{
    Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 22);
    printTreeStructure(root, 0);
    return 0;
}
