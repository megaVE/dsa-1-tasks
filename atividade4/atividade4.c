/*-------------------------------------------------------------
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTACAO.
* Trabalho...: Atividade 4
* Disciplina.: Programacao
* Professor..: Luiz Eduardo da Silva
* Aluno......: Vinícius Eduardo de Souza Honório
* Data.......: 06/08/2021
*-------------------------------------------------------------*/

#include <stdio.h>

void leSudoku (int n, int sudoku [16] [16])
{
    char s[2];
    int i, j, dim = n * n;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
        {
            scanf("%s", s);
            if (s[0] >= '1' && s[0] <= '9')
                sudoku[i][j] = s[0] - '0';
            if (s[0] >= 'A' && s[0] <= 'G')
                sudoku[i][j] = s[0] - 'A' + 10;
        }
}

void imprimeLinha (int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("+");
        for (j = 0; j < n; j++)
            printf("---");
    }
    printf("+\n");
}

void imprimeSudoku (int n, int sudoku[16][16])
{
    int i, j, dim = n * n;
    imprimeLinha(n);
    for (i = 0; i < dim; i++)
    {
        printf("|");
        for (j = 0; j < dim; j++)
        {
            int num = sudoku[i][j];
            if (num <= 9)
                printf("%2d ", num);
            else
                printf("%2c ", num - 10 + 'A');
            if ((j + 1) % n == 0)
                printf("|");
        }
        printf("\n");
        if ((i + 1) % n == 0)
            imprimeLinha(n);
    }
}

/*--------------------------------------------------
* Funcao que testa uma solucao de Sudoku
* Parametros:
*    n = dimensao das regioes
*    sudoku - jogo preenchido
* Retorna:
*    1 se a matriz e uma solucao do sudoku
*    0 caso contrario, modificando os parametros
*      lin e col para indicar a linha e coluna onde
*      foi detectado o problema.
*--------------------------------------------------*/
int sudokuOk(int n, int sudoku[16][16], int *lin, int *col)
{
    int i, j, k;
    /* Variáveis de controle de repetição */

    int s, c;
    int r = 1;
    int it, jt, ct, temp;
    /* Variáveis de detecção de erro
    * s = soma todos os números em uma determinada linha ou coluna
    * c = define o limite da soma das linhas, colunas e regiões; detectando, assim, o erro
    * r = número retornado pela função (1, quando a solução for correta; 0, quando a solução for incorreta)

    int temp, it, jt, ct;
    /* Variáveis de busca do erro no bloco */
    
    /* Definindo o limite da soma das linhas, colunas e blocos */
    switch (n)
    {
        case 2:
         c = 10; // = 1 + 2 + ... + 4
         break;

        case 3:
         c = 45; // = 1 + 2 + ... + 9
         break;

        case 4:
         c = 136; // = 1 + 2 + ... + 16
         break;
    }

    /* Conversor de letras hexadecimais para decimais */
    if (n == 4)
    {
        for (i = 0; i < 16; i++)
        {
            for (j = 0; j < 16; j++)
            {
                switch (sudoku[i][j])
                {
                    case 'A':
                     sudoku[i][j] = 10;
                     break;

                    case 'a':
                     sudoku[i][j] = 10;
                     break;

                    case 'B':
                     sudoku[i][j] = 11;
                     break;

                    case 'b':
                     sudoku[i][j] = 11;
                     break;

                    case 'C':
                     sudoku[i][j] = 12;
                     break;

                    case 'c':
                     sudoku[i][j] = 12;
                     break;

                    case 'D':
                     sudoku[i][j] = 13;
                     break;

                    case 'd':
                     sudoku[i][j] = 13;
                     break;

                    case 'E':
                     sudoku[i][j] = 14;
                     break;

                    case 'e':
                     sudoku[i][j] = 14;
                     break;

                    case 'F':
                     sudoku[i][j] = 15;
                     break;

                    case 'f':
                     sudoku[i][j] = 15;
                     break;

                    case 'G':
                     sudoku[i][j] = 16;
                     break;

                    case 'g':
                     sudoku[i][j] = 16;
                     break;

                    default:
                     break;
                }
            }
        }
    }

    i = 0;
    while (i < (n * n) && r != 0) // Varredor de Linhas
    {
        s = 0;
        for (j = 0; j < (n * n); j++)
        {
            s = s + sudoku[i][j];
        }
        if (s != c)
        {
            *lin = (i + 1);
            r = 0;
            for (temp = 1, ct = 0; temp <= (n * n) && ct < 2; temp++)
            {
                ct = 0;
                for (jt = 0; jt < (n * n) && ct < 2; jt++)
                {
                    if (sudoku [i][jt] == temp)
                    {
                        ct++;
                        if (ct == 2)
                        {
                            *col = (jt + 1);
                        }
                    }
                }
            }
        }
        i++;
    }
    
    j = 0;
    while (j < (n * n) && r != 0) // Varredor de Colunas
    {
        s = 0;
        for (i = 0; i < (n * n); i++)
        {
            s = s + sudoku[i][j];
        }
        if (s != c)
        {
            *col = (j + 1);
            r = 0;
            for (temp = 1, ct = 0; temp <= (n * n) && ct < 2; temp++)
            {
                ct = 0;
                for (it = 0; it < (n * n) && ct < 2; it++)
                {
                    if (sudoku [it][j] == temp)
                    {
                        ct++;
                        if (ct == 2)
                        {
                            *lin = (it + 1);
                        }
                    }
                }
            }
        }
        j++;
    }

    k = 0;
    s = 0;
    while (k < n && r != 0) // Varredor de Blocos
    {
        printf("\nVai varrer blocos");
        for (j = 0; j < (n * n) && r != 0; j++)
        {
            printf("\nj = %d", j);
            for (i = (k * n); i < ((k + 1) * n) && r != 0; i++)
            {
                printf("\ni = %d", i);
                s = s + sudoku[i][j];
            }
            if ((j + 1) % n == 0)
            {
                printf("\ns = %d\n", s);
                if (s != c)
                {
                    printf("\ni = %d, j = %d\n", i, j);
                    r = 0;
                    i--;
                    for (temp = 1, ct = 0; temp <= (n * n) && ct < 2; temp++)
                    {
                        ct = 0;
                        for (it = (i - n + 1); it < (i + 1); it++)
                        {
                            for (jt = (j - n + 1); jt < (j + 1); jt++)
                            {
                                if (temp == sudoku[it][jt])
                                {
                                    ct++;
                                    if (ct == 2)
                                    {
                                        *lin = (it + 1);
                                        *col = (jt + 1);
                                    }
                                }
                            }
                        }
                    }
                }
                s = 0;
            }
        }
        k++;
    }

    return r;
}

int main (void)
{
    int n, nlin, ncol, ok;
    int sudoku[16][16];
    scanf("%d", &n);
    leSudoku(n, sudoku);
    imprimeSudoku(n, sudoku);
    ok = sudokuOk(n, sudoku, &nlin, &ncol);
    if (ok)
        puts("Sudoku Ok!");
    else
        printf("Erro na posição (%d,%d)\n", nlin, ncol);
    return 0;
}