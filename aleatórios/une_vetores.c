#include <stdio.h>
#include <stdlib.h>

void readArray(int s, int **a){
    int aux;
    printf("\n* Inicio da Leitura Array *\n(Os vetores devem ser colocados de forma ordenada)\n\n");
    for(int i = 0; i<s; i++, a++){
        printf("Digite o valor do %dº elemento: ", i+1);
        scanf("%d", a);
    }
}

void printArray(int s, int **a){
    for(int i = 0; i<s; i++, a++){
        printf("%d, ", *a);
    }
}

void podwojonySort(int **a, int sa, int **b, int sb, int **c){
    for(int *i=c, *j=a, *k=b;i<c;i++){
        if(*a < *b){
            *i = *j;
            j++;
        }
        else{
            *i = *k;
            k++;
        }
    }
}

int main(void){
    int k, j;
    int *u, *v, *w;

    printf("Informe o tamanho do primeiro vetor: ");
    scanf("%d", &j);
    u = (int *)malloc(sizeof(int) * j);
    readArray(j, u);
    printf("\n- Primeiro Vetor -\n");
    printArray(j, u);

    printf("\nInforme o tamanho do segundo vetor: ");
    scanf("%d", &k);
    v = (int *)malloc(sizeof(int) * k);
    readArray(k, v);
    printf("\n- Segundo Vetor -\n\n");
    printArray(k, v);

    w = (int *)malloc(sizeof(int) * (k+j));

    podwojonySort(u, j, v, k, w);
    printArray(j+k, w);
}