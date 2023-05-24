#include <stdio.h>

void insert(int v[], int n) {

    int i, j, x;

    for(i = 1; i < n; i++) {

        x = v[i];      

        for(j = i-1; j >= 0 && v[j] > x; j--){
            v[j+1] = v[j];
        }
        
        v[j+1] = x;

    }
    
}

int main()
{
    int vetor[] = {7,8,40,13,24,2,50,32};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    
    insert(vetor, n);
    
    printf("Vetor ordenado:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
