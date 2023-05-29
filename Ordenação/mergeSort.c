#include <stdio.h>
#include <stdlib.h>

void intercala(int x, int y, int w, int v[]){
    int i, j, k, *m;
    m = malloc ((w-x) * sizeof(int));
    i = x;
    j = y;
    k = 0;
    
    while (i < y && j < w) {
        if(v[i] <= v[j]){
            m[k++] = v[i++];
        } else {
            m[k++] = v[j++];
        }
    }
    
    while (i < y){
        m[k++] = v[i++];
    }
    
    while (j < w){
        m[k++] = v[j++];
    }
    
    for(i = x; i < w; i++){
        v[i] = m[i-x];
    }
    
    free(m);
}

void mergeSort(int v[], int n){
    int i = 1;
    int  j, k;
    
    while(i < n){
        j = 0;
        while(j + i < n){
            k = j + 2*i;
            if(k > n){
                k = n;
            }
            intercala(j, j+i, k, v);
            j = j + 2*i;
        }
        i = i * 2;
    }
}

int main()
{
    int v[] = {10, 7, 53, 21, 49, 14, 35};
    int n = sizeof(v) / sizeof(v[0]);
    
    mergeSort(v, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    return 0;
}
