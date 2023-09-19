#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TAMANHO = 9500;

void ordenado(int TAMANHO, int *vetor)
{
    int x;
    for(x = 0; x < TAMANHO; x++)
        vetor[x] = (x + 1);
}

void desordenado(int TAMANHO, int *vetor)
{
    int x;
    srand(time(NULL));
    for(x = 0; x < TAMANHO; x++)
        vetor[x] = (rand() % TAMANHO);
}

void inversamente_ordenado(int TAMANHO, int *vetor)
{
    int x;
    for(x = 0; x < TAMANHO; x++)
        vetor[x] = (TAMANHO - x);
}

int main (void)
{
    int i, j, aux, vetor [TAMANHO], contador, s;
    contador = 0;
    printf("Tipo de vetor: ");
    scanf("%d", &s);
    switch(s)
    {
        case (1):
         ordenado(TAMANHO, vetor);
         break;

        case (2):
         desordenado(TAMANHO, vetor);
         break;

        case (3):
         inversamente_ordenado(TAMANHO, vetor);
         break;
    }
    for(i = (TAMANHO - 1); i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                contador++;
                vetor[j] = vetor[j + 1];
                contador++;
                vetor[j + 1] = aux;
                contador++;
            }
        }
    }
    puts("Vetor Ordenado:");
    for(i = 0; i < TAMANHO; i++)
        printf("%d ", vetor[i]);
    printf("\nTrocas necessárias: %d", contador);
    return 0;
}