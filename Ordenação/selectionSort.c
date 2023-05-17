#include <stdio.h>

void selectionSort(int v[], int n){
    
    int i, j, min, x;
    
    for(i = 0; i < n - 1; i++){
        
        min = i;
        
        for(j = i+1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

int main()
{
    int vetor[] = {10, 27, 5, 4, 32, 40, 13};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    
    selectionSort(vetor, n);

    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    
    return 0;
}