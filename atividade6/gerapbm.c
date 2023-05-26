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
    FILE *f;
    int i, j;

    f = fopen(name, "wt");

    fputs("P1\n", f);
    fputs("#(comentario da imagem)\n", f);
    fprintf(f, "%d %d\n", nc, nl);
    fprintf(f, "%d ", img[0]);

    for(i = 1; i < (nl * nc); i++)
    {
        if (i % 100 == 0)
            fprintf(f, "\n%d ", img[i]);
        else
            fprintf(f, "%d ", img[i]);
    }
    fprintf(f, "\n");

    fclose(f);
}

image read_pts(char *name, int *nl, int *nc)
{
    FILE *f;
    image img = NULL;
    int i, n, n1, n2, x, y;

    f = fopen(name, "rt");

    fscanf(f, "%d %d\n", &n1, &n2);
    *nc = n1;
    *nl = n2;

    fscanf(f , "%d", &n);

    img = (int *)malloc(n1 * n2 * sizeof(int));

    for(i = 0; i < (n1 * n2); i++)
        img[i] = 0;

    for(i = 0; i < n; i++)
    {
        fscanf(f, "%d", &x);
        fscanf(f, "%d", &y);
        img[((x * n1) + y)] = 1;
    }
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
