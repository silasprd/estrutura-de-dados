#include <stdio.h>

void selectionSort(int v[], int n){
    
    //variáveis de controle de loop
    int i, j, 
    //variáveis do índice menor e para relizar as trocas
    int min, x;
    
    for(i = 0; i < n - 1; i++){
        
        min = i;
        
        for(j = i+1; j < n; j++){
            //verifica se o valor na posição j é menor que o valor na posição min(i)
            if(v[j] < v[min]){
                //atualiza o valor de min para posição j pois nele encontrou um valor menor
                min = j;
            }
        }
        //armazena o valor do elemento atual na variável x
        x = v[i];
        //atribui o valor do menor elemento encontrado(posição min) à posição atual do vetor(posição i)
        v[i] = v[min];
        //atribui o valor armazenado em x à posição min do vetor, realizando a troca
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