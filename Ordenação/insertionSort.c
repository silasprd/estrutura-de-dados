#include <stdio.h>

void insert(int v[], int n) {
    int i, j, x;
    for(i = 1; i < n; i++) {
        //armazena a 2ªposição do vetor na variável x
        x = v[i];
        
        //realiza um for para empurrar os valores para direira em caso do vetor na posição anterior(j) ser menor que o valor posterior armazenado
        for(j = i-1; j >= 0 && v[j] > x; j--){
            //atualiza j para indicar posição anterior à correta para armazenar x após o deslocamento 
            v[j+1] = v[j];
        }
        
        //x é armazenado na posição posterior de j que indicava a posição anterior à correta
        v[j+1] = x;
    }
}

int main()
{
    int vetor[] = {7,8,40,13,24,2,50,32};
    //define um novo vetor n com o tamanho do vetor original
    int n = sizeof(vetor) / sizeof(vetor[0]);
    
    insert(vetor, n);
    
    printf("Vetor ordenado:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}

// Complexidade de tempo O(n²)
// É boa em casos em que:
// Se tenha pequenas quantidades de elementos 
// Em sequências de entrada quase ordenadas, pois a inserção de um elemento em uma posição quase correta requer um número menor de comparações
// Quando se tem uma parte da sequência já ordenada, pode ser eficiente para ordenar a parte desornada
