/**
 * Armstrong数(阿姆斯壮数): n位数的各位数的n次方之和等于该数
 * 如:
 *  153=1^3+5^3+3^3
 *  1634=1^4+6^4+3^4+4^4
*/

#include <stdio.h>
#include <math.h>

int main()
{
    unsigned char flag;
    int number, originalNumber, originalNumber1, remainder, result = 0;
 
    printf("请输入一个数: ");
    scanf("%d", &number);
 
    originalNumber = number;
    originalNumber1 = number;

    //判断数据长度
    while (originalNumber != 0)
    {
        originalNumber /= 10;
        flag++;
    }

    //计算各部分n次方
    while (originalNumber1 != 0)
    {
        remainder = originalNumber1%10;
        result += pow(remainder, flag);
        originalNumber1 /= 10;
    }
 
    if(result == number)
        printf("%d 是 Armstrong 数",number);
    else
        printf("%d 不是 Armstrong 数",number);
 
    return 0;
}