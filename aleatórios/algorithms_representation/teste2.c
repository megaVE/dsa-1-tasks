#include <stdio.h>

int main (void)
{
    int i, j;
    j = 0;
    for(i = 0; i < 10 && j == 0; i++)
    {
        scanf("%d", &j);
        printf("j = %d; i = %d\n", j, i);
    }
    printf("\ni = %d", i);
}