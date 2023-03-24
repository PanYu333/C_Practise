/**
 * 斐波那契数列: 1 1 2 3 5 8 13 21...
*/

#include <stdio.h>

int Fibonacci(int n);
void sequence_fibo(int n);

int main()
{
    int i, j;
    i = Fibonacci(5);
    printf("%d\n", i);

    j = 10;
    sequence_fibo(j);

    return 0;
}

/*输出第n个斐波那契数, i从零开始*/
int Fibonacci(int n)
{
    if(n == 1 || n == 2)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

/*输出n个斐波那契数列*/
void sequence_fibo(int n)
{
    int i, t1 = 1, t2 = 1;

    for (i = 0; i < n; i++)
    {
        printf("%d ", t1);
        t2 = t1 + t2;
        t1 = t2 - t1;
    }
}