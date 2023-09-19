#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int i, n;
    int *x;

    *x = NULL;
    scanf("%d", &n);

    *x = (int *)malloc(n * (sizeof(int)));
    printf("Tamanho de um inteiro = %d bytes\n", sizeof(int));
    printf("Tamanho do vetor = %d bytes\n", sizeof(x));
    for(i = 0; i < n; i++)
    {
        x[i] = 7;
        printf("%d ", x[i]);
    }
}