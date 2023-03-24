/**
 * 素数：一个数只能被自身和1整除
 * 判定方法：
 *  1. 素数的因子不会超过本身的1/2， 遍历2~N/2
 *  2. 素数的因子中其中一个不会超过本身的开平方，遍历2~sqrt(n)
*/

#include <stdio.h>
#include <math.h>

int prime_num(int n);

int main()
{
    char flag;
    int i, n;
    printf("请输入一个数：");
    scanf("%d", &n);

    // for (i = 2; i <= sqrt(n); i++)
    // {
    //     if (n % i == 0)
    //     {
    //         flag = 1;
    //         break;
    //     }
        
    // }
    // if (flag != 0)
    //     printf("%d 不是素数!\n", n);
    // else
    //     printf("%d 是素数!\n", n);

    int a = prime_num(n);
    if (a != 0)
        printf("%d 是素数!\n", n);
    else
        printf("%d 不是素数!\n", n);
    return 0;
}

/*函数形式判断素数*/
int prime_num(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;       //不是素数
    }
    return 1;
}
