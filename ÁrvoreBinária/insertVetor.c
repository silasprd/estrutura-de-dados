#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *insert(Node *root, int values[], int n) {

    if (root == NULL) {
        Node *new = malloc(sizeof(Node));

        new->value = values[0];
        new->left = NULL;
        new->right = NULL;
        root = new;
    }

    for (int i = 1; i < n; i++) {

        Node *f = root;
        Node *p = NULL;
        Node *new = malloc(sizeof(Node));

        if (new == NULL) {
            return root;
        }

        new->value = values[i];
        new->left = NULL;
        new->right = NULL;

        while (f != NULL) {

            p = f;

            if (f->value > new->value) {
                f = f->left;
            } else {
                f = f->right;
            }
        }

        if (p->value > new->value) {
            p->left = new;
        } else {
            p->right = new;
        }
    }

    return root;
    
}

Node* removeRoot(Node *root){

    Node *p, *f;
    
    if(root->left == NULL && root->right == NULL){
        f = root->right;
        free(root);
        return NULL;
    }

    if(root->left == NULL){
        f = root->right;
        free(root);
        return f;
    } else {
        p = root; f = root->left;
        while(f->right != NULL){
            p = f;
            f = f->right;

            if(p != root){
                p->right = f->left;
                f->left = root->left;
            }
        }
        f->right = root->right;
    }
    
    free(root);
    return f;
}

// void print(Node *root){
//     if(root != NULL){
//         print(root->left);
//         printf("%d ", root->value);
//         print(root->right);
//     }
// }

void printTreeStructure(Node *root, int space) {

    if (root == NULL){
        return;
    }

    printTreeStructure(root->right, space + 1);

    for (int i = 0; i < space; i++) {
        printf("    ");
    }

    printf("%d\n", root->value);

    printTreeStructure(root->left, space + 1);
}

int main() {
    
    Node *root = NULL;
    int values[] = {21, 32, 4, 11, 12, 50};
    int n = sizeof(values) / sizeof(values[0]);
    
    root = insert(root, values, n);
    root = removeRoot(root);
    printTreeStructure(root, 0);
    
    return 0;
    
}
