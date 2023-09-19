#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(__WIN64__) || defined(__CYGWIN__)
#define VIEW "./i_view32"
#elif defined(__linux__)
#define VIEW "eog"
#endif

typedef int *image;

image alloc_memo(int nl, int nc)
{
    return (image)malloc(nl * nc * sizeof(int));
}

void write_pbm(image img, char *name, int nl, int nc)
{
    printf("Vai escrever\n");

    FILE *f;
    int i, j;

    /* 1. */

    f = fopen(name, "wt");

    printf("Abriu, Arquivo: %s\n", name);

    /* 2. */

    fputs("P1\n", f);

    printf("Número Mágico escrito\n");

    /* 3. */

    fputs("#(comentario da imagem)\n", f);

    printf("Comentário escrito\n");

    /* 4. */

    fprintf(f, "%d %d\n", nc, nl);

    printf("Linhas (%d) e Colunas (%d) escritas\n", nl, nc);

    /* 5. */

    fprintf(f, "%d ", img[0]);
    for(i = 1; i < (nl * nc); i++)
    {
        if (i % 100 == 0)
            fprintf(f, "\n%d ", img[i]);
        else
            fprintf(f, "%d ", img[i]);
    }
    fprintf(f, "\n");

    printf("Matriz da imagem, de maior elemento %d, escrita", i);

    // --------------------------------------------
    // TO DO
    // 1. criar o arquivo texto 'name'
    // 2. gravar o numero mágico 'P1' no arquivo
    // 3. gravar uma linha de comentário '#...'
    // 4. gravar o número de linhas e colunas
    // 5. gravar os 0's ou 1's da imagem
    //    (no máximo 100 valores por linha)
    // --------------------------------------------
    fclose(f);
}

image read_pts(char *name, int *nl, int *nc)
{
    printf("Vai ler\n");

    FILE *f;
    image img = NULL;
    int i, n, n1, n2, x, y;

    /* 1. */

    f = fopen(name, "rt");

    printf("Abriu, Arquivo: %s\n", name);
    
    /* 2. */

    fscanf(f, "%d %d\n", &n1, &n2);
    *nc = n1;
    *nl = n2;

    printf("Leu linhas (%d) e colunas (%d)\n", *nc, *nl);

    /* 3. */

    fscanf(f , "%d", &n);

    printf("Leu o número de pontos (%d)\n", n);

    /* 4. */

    printf("Tamanho do vetor = %d\n", (n1 * n2));

    img = (int *)malloc(n1 * n2 * sizeof(int));

    printf("Memória alocada = %d bytes\n", sizeof(image));

    /* 5. */

    for(i = 0; i < (n1 * n2); i++)
        img[i] = 0;

    printf("Vetor zerado, último índice: %d\n", (i - 1));

    /* 6. */

    for(i = 0; i < n; i++)
    {
        fscanf(f, "%d", &x);
        fscanf(f, "%d", &y);
        printf("%d ", x);
        printf("%d\n", y);
        img[((x * n1) + y)] = 1;
    }

    printf("Vetor preenchido, com %d pixels\n", i);

    // --------------------------------------------
    // TO DO
    // 1. abrir o arquivo texto 'nome' para leitura
    // 2. ler o número de linhas e colunas
    // 3. ler o número 'n' de pontos
    // 4. alocar o vetor 'img' com nl x nc
    //    elementos
    // 5. preencher o vetor imagem com zeros
    // 6. ler as 'n' coordenadas (i, j) e preencher
    //    a posição correspondente de img com 1.
    // --------------------------------------------
    fclose(f);
    return img;
}
int main(int argc, char *argv[])
{
    image in;
    char *p;
    char nameIn[40];
    char nameOut[40];
    char command[100];
    int nl, nc;
    if (argc < 2)
    {
        printf("Uso: %s <imagem[.pts]>\n\n", argv[0]);
        return 1;
    }
    if (p = strstr(argv[1], ".pts"))
        *p = 0;
    strcpy(nameIn, argv[1]);
    strcat(nameIn, ".pts");
    strcpy(nameOut, argv[1]);
    strcat(nameOut, ".pbm");

    // transformation
    in = read_pts(nameIn, &nl, &nc);
    write_pbm(in, nameOut, nl, nc);

    sprintf(command, "%s %s &", VIEW, nameOut);
    system(command);
    free(in);
    return 0;
}