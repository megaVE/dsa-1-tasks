#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TAMANHO = 30;

int main (void)
{
    int i;
    srand(time(NULL));
    for(i = 0; i < TAMANHO; i++)
        printf("%d", rand() % TAMANHO);
}