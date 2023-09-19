#include <stdio.h>

const int TAMANHO = 10;

int main (void)
{
    int i;
    for(i = TAMANHO; i >= 1; i--)
        printf("%d ", i);
    return 0;
}