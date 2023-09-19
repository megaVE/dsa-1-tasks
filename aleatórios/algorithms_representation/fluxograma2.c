#include <stdio.h>

int main (void)
{
    int count;
    int I;
    int Codigo [8];
    char Nome [8] [10];
    int Idade [8];
    char Cargo [8] [30];
    int EndProx [8];

    Codigo [1] = 0;
    Nome [1] [0] = '\0';
    Idade [1] = 0;
    Cargo [1] [0] = '\0';
    EndProx [1] = 5;

    for (count = 2; count < 8; count++)
    {
        printf ("Digite o código do %dº registrado: ", count+2);
        scanf ("%d", &Codigo [count]);
    }

    for (count = 2; count < 8; count++)
    {
        printf ("Digite o nome do %dº registrado: ", count+2);
        scanf ("%s", Nome [count]);
        while (getchar () != '\n');
    }

    for (count = 2; count < 8; count++)
    {
        printf ("Digite a idade do %dº registrado: ", count+2);
        scanf ("%d", &Idade [count]);
    }

    for (count = 2; count < 8; count++)
    {
        printf ("Digite o cargo do %dº registrado: ", count+2);
        scanf ("%s", Cargo [count]);
        while (getchar () != '\n');
    }

    for (count = 2; count < 8; count++)
    {
        printf ("Digite o End_Prox do %dº registrado: ", count+2);
        scanf ("%d", &EndProx);
    }

    I = EndProx[1];

    while (I != 0)
    {
        printf ("%d, %s, %d, %s\n", Codigo [I], Nome [I], Idade [I], Cargo [I]);
        I = EndProx [I];
    }
    return 0;
}