#include <stdio.h>

int main()
{
    unsigned char i, j;

    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%dx%d=%d ", j, i, i * j);
        }
        printf("\n");
    }
    return 0;   
}
