#include <stdio.h>

int main (void)
{
    int x, y, z;
    printf ("Digite os 3 valores :");
    scanf ("%d %d %d", &x, &y, &z);
    while ((2 * x) < z)
    {
        if (((y + z) % 5) > 2)
        {
            y = (y - (z % 5));
            x = x + 2;
            z = z - y;
        }
        else
        {
            y = y - x;
            x = x - 1;
            z = z + y;
        }
        printf("Parciais %d %d %d\n", x, y, z);
    }
    return 0;
}