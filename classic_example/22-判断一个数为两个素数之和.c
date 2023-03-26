/**
 * 查看输入的一个数是否为两个素数之和
 * 如果是则打印出相应的加法操作
*/

#include <stdio.h>

char checkPrime(int n);

int main()
{
    char flag = 0;
    int i, number;

    printf("请输入一个数：");
    scanf("%d", &number);

    for (i = 2; i <= number / 2; ++i)
    {
        if (checkPrime(i) && checkPrime(number - i))
        {
            printf("%d = %d + %d\n", number, i, number - i);
            flag = 1;
        }
    }

    if (flag == 0)
        printf("该数不能被分解为两个素数之和!\n");

    return 0;
}

char checkPrime(int n)
{
    int i, isprime = 1;
    for (i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            isprime = 0;
            break;
        }
    }
    return isprime;
}
