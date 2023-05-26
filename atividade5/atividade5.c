/*-------------------------------------------------------------
*          UNIFAL - Universidade Federal de Alfenas.
*            BACHARELADO EM CIENCIA DA COMPUTACAO.
* Trabalho..: Atividade 5
* Disciplina: Programacao
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Vinícius Eduardo de Souza Honório
* Data......: 21/06/2021
*-------------------------------------------------------------*/
#include <stdio.h>

void readisbn (int *proximo, char *entrada, int *codigo)
{
    int i;
    
    for (i = 0; i < 9; i++)
    {
        entrada[i] = getchar();
    }
    while (getchar() != '\n');
    entrada[i] = '\0';

    /* Leitura do código */

    for (i = 0; i < 9 && entrada[i] == '0'; i++);
    if (i == 9)
        *proximo = 0;

    /* Verificando se o código é "000000000" */

    for (i = 0; i < 9; i++)
    {
        if (entrada[i] == 'x' || entrada[i] == 'X')
            codigo[i] = 10;
        else
            codigo[i] = (entrada[i] - '0');
    }

    /* Transformando os caracteres em números inteiros e alocando-os em outro vetor */
}
char isbn_dv (int *codigo)
{
    int i, s;
    int s1[10];
    int s2[10];

    s1[0] = codigo[0];
    for (i = 1; i < 9; i++)
    {
        s1[i] = s1[(i - 1)] + codigo[i];
    }

    /* Determinando s1 */

    s2[0] = codigo[0];
    for (i = 1; i < 9; i++)
    {
        s2[i] = s2[(i - 1)] + s1[i];
    }

    /* Determinando s2 */

    if ((s1[8] + s2[8]) % 11 == 0)
        s = 0;
    else
        s = 11 - (s1[8] + s2[8]) % 11;

    /* Obtendo o último dígito do código */

    for (i = 0; i < 9; i++)
    {
        if (codigo[i] == 10)
            printf("X");
        else
            printf("%d", codigo[i]);
    }

    if (s == 10)
        printf("-X\n");
    else
        printf("-%d\n", s);

    /* Imprime o código, com o dígito verificador */
}

int main (void)
{
    char entrada [9];
    int codigo [9];
    int proximo = 1;
    /*
    * entrada = string que armazena o código inserido pelo usuário
    * codigo = vetor de inteiros que armazena o código inserido pelo usuário em formato inteiro
    * proximo = variável condicional para continuidade de operação do programa
    */
    readisbn(&proximo, entrada, codigo);
    while (proximo)
    {
        isbn_dv(codigo);
        readisbn(&proximo, entrada, codigo);
    }
    return 0;
}