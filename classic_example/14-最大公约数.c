/**
 * 设a, b待求数, gcd: 最大公约数, lcm: 最小公倍数;
 * 定理: a * b = gcd * lcm;
 * 
 * 辗转相除法:
 *   求两个数字相除的余数c=a%b，如果余数c为0，则b为最大公约数。如果b不为零，a=b,b=c,循环计算。
 * 
 * 最大公约数(相减法): 
 *   如果a>b，则a=a-b;如果b>a,则b=b-a。一直循环计算直到a=b，则此时a、b的值即为所求最大公约数。
 * 最小公倍数(叠乘法):
 *   公倍数一定与这两个数存在倍数关系，那么求解最小公倍数我们就可以将其中一个数依次扩大1倍、2倍、3倍……
 *   直到出现第一个扩大n倍的数可以同时整除这两个数，这个数就是最小公倍数。
 */

#include <stdio.h>

int recursion_gcd(int a, int b);
void subtraction_gcd(int a, int b);
void multi_lcm(int a, int b);
void sequence_gcd_lcm(int a, int b);

int main()
{
    int a, b, lcm, gcd;
    printf("请输入两个数: ");
    scanf("%d %d", &a, &b);

    gcd = recursion_gcd(a, b);  //递归法辗转相除
    lcm = a * b / gcd;          //定理

    printf("递归后得%d, %d的最大公约数和最小公倍数分别为: %d %d\n", a, b, gcd, lcm);

    subtraction_gcd(a, b);
    multi_lcm(a, b);
    sequence_gcd_lcm(a, b);
    return 0;
}


/*辗转相除法递归*/
int recursion_gcd(int a, int b)
{
    if(b != 0)
        return recursion_gcd(b, a % b);
    else
        return a;
}


/*相减法求最大公约数*/
void subtraction_gcd(int a, int b)
{
    printf("相减法得%d, %d的最大公约数为: ", a, b);

    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    printf("%d\n", a);
}

/*叠乘法求最小公倍数*/
void multi_lcm(int a, int b)
{
    int i = 1;
    while (a * i % b != 0)
    {
        i++;
    }
    printf("叠乘法得%d, %d的最小公倍数数为: %d\n", a, b, a * i);
}


/*遍历求最大公约数, 最小公倍数*/
void sequence_gcd_lcm(int a, int b)
{
    int gcd, lcm;
    gcd = a > b ? b : a;
    lcm = a > b ? a : b;
    
    while(a % gcd != 0 || b % gcd != 0)     //不能同时整除
    {
        gcd--;
    }
    while (lcm % a != 0 || lcm % b != 0)
    {
        lcm++;
    }
    printf("遍历后得%d, %d的最大公约数和最小公倍数分别为: %d %d\n", a, b, gcd, lcm);
}