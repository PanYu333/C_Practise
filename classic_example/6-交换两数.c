#include <stdio.h>

void swap(int *a, int *b);
int main()
{
    int a = 1, b = 3;
    printf("交换前: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("交换后: a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *a, int *b)
{
    *b = *a + *b;
    *a = *b - *a;
    *b = *b - *a;
}