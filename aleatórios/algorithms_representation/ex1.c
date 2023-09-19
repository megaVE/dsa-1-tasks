/*
Para uma turma com 8 alunos e cada aluno tem 3 notas.
Declare uma estrutura matriz para armazenar as notas desses alunos
*/

#include <stdio.h>

int main (void)
{
    float notas [3] [8];
    int ialuno, inota;
    for (ialuno = 1; ialuno <= 8; ialuno++)
    {
        for (inota = 1; inota <= 3; inota++)
        {
            printf ("Digite a nota %d do aluno %d:", &inota + 1, &ialuno + 1);
            scanf ("%f", &notas [inota] [ialuno]);
        }
    }
    printf ("%3d", notas [inota] [ialuno]);
    return 0;
}