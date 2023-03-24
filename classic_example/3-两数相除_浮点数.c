/**
 * 32位浮点型的表示: 1个符号位,8位指数(阶数)exp(E - bias)，23位尾数M; 64位:1 + 11 + 52
 * 运算规则：1.M x 2^E, bias = 2^exp-1
 *      例: 178.125D = 10110010.001B = 1.0110010001 * 2^111
 *          符号位: 0
 *          阶数: 7 + 127 = 134 = 10000110
 *          尾数: .0110010001
 *          二进制存储形式: 0 10000110 0110010_00100000_00000000
 * 分子分母都是整形，结果会向下取整，一方是浮点型，结果就是浮点型
 */

#include <stdio.h>

int main()
{
    int   z = 10,   m1 = 4;
    float result1,  result2;

    result1 = z / m1;
    result2 = z / (float)m1;
    printf("10 / 4 = %.2f\n", result1);
    printf("10 / 4.0 = %.2f\n", (int)result2);
    return 0;
}