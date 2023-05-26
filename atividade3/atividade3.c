/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*           UNIFAL − Universidade Federal de Alfenas.
*            BACHARELADO EM CIENCIA DA COMPUTACAO.
* Trabalho..: Atividade 3
* Disciplina: Programacao
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Vinícius Eduardo de Souza Honório
* Data......: 27/07/2021
*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
#include <stdio.h>
/*-------------------------------------------------------
* Calcula o comprimento do string
* Recebe o string (s)
* Retorna o comprimento de s
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-*/
int strlenght (char *s)
{
    int i;
    for (i = 0; s[i]; i++)
        ;
    return i;
}
/*-------------------------------------------------------
* Le um string
* Parametros
*    s = string a ser lido
*    len = tamanho maximo de leitura (contar o \0 e \n)
*-------------------------------------------------------*/
void strread (char *s, int len)
{
    fgets (s, len, stdin);
    s[strlenght(s) - 1] = '\0';
}
/*-------------------------------------------------------
* Mostra os elementos do vetor string em modo texto
* Parametros:
*    s = string
*    name = nome do string
*-------------------------------------------------------*/
void strshow(char *s, char *name)
{
    int i;
    for (i = 0; s[i]; i++)
        printf ("%3d ", i);
    printf ("%3d\n", i );
    for (i = 0; s[i]; i++)
        printf ("+---");
    printf ("+---\n");
    for (i = 0; s[i]; i++)
        printf ("| %c ", s[i]);
    printf ("| \\0| %s\n", name);
    for (i = 0; s[i]; i++)
        printf ("+---");
    printf ("+---+\n");
}
/*-------------------------------------------------------
* Insere um substring num string na posicao especificada
* Parametros:
*    pos = posicao onde inserir (0 e a primeira posicao)
*    sub = substring que sera inserido em s
*    s   = string onde inserir sub
*-------------------------------------------------------*/
void strinsert (int pos, char *sub, char *s)
{
    int i = 0; // Variável auxiliar de contagem
    int j; // Variável auxiliar de contagem
    char part2 [(strlenght(s) - pos)]; // Segunda parte do string que será coletada e recolocada no final do mesmo, após a inserção
    if (pos > strlenght(s))
    {
        pos = strlenght(s);
    }
    for (j = pos; j < strlenght(s); j++)
    {
        part2[i] = s [j];
        i++;
    }
    part2[i] = '\0';
    i = pos;
    for (j = 0; j < strlenght(sub); j++)
    {
        s[i] = sub[j];
        i++;
    }
    for (j = 0; j < strlenght(part2); j++)
    {
        s[i] = part2[j];
        i++;
    }
    s [i] = '\0';
}
/*-------------------------------------------------------
* transforma um string literal em inteiro
* o literal pode ter um sinal (+ ou -) seguido de digitos
*-------------------------------------------------------*/
int str2int (char *s)
{
    int i = 0; // Variável auxiliar de contagem
    int in = 0; // Resultado da conversão a ser retornado

    if (s[0] == '-' || s[0] == '+') 
    {
        i++;
    }
    while (s[i] != '\0')
    {
        in = (in * 10 + (s[i] - '0'));
        i++;
    }
    if (s[0] == '-')
    {
        in = -(in);
    }
    return in;
}
int main (void)
{
    char string [100];
    char substring [100];
    char posstr [4];
    int posicao;
    do
    {
        strread(posstr, 4);
        posicao = str2int(posstr);
        printf("\nPosição = %d\n", posicao);
        if (posicao >= 0)
        {
            strread(substring, 30);
            strshow(substring, "substr.");
            strread(string, 70);
            strshow(string, "string");
            strinsert(posicao, substring, string);
            strshow(string, "result.");
        }
    } while (posicao >= 0);
}