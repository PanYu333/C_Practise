/**
 * 表格形式打印数据
*/

#include <stdio.h>

int main(int argc, int **argv[])
{
    int i, j;
    int start = 2, end = 10;

    for (i = start; i <= end; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            printf("%4d", j * i);
        }

        printf("\n");
    }
}