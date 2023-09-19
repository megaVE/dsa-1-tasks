#include <stdio.h>

int main (void)
{
    int x = 0;
    int soma = 0;
    while (x <= 7)
    {
        x = x + 1;
        soma = soma + x + 1;
    }
    
    printf ("%d, %d", x, soma);
}