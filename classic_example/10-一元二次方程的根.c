/**
 * f(x) = ax^2 + bx + c
 * △ = sqrt(b^2 - 4ac)
 * 根为: x1 = (-b + △) / 2a, x2 = (-b - △) / 2a
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float p, q;
    float alpha, x1, x2;

    printf("请输入参数a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    alpha = b * b - 4 * a * c;

    if(alpha < 0)
        printf("函数f(x) = %fx^2 + %fx + %f无解!\n", a, b, c);
    else
    {
        p = (-b)  / (2 * a);
        q = sqrt(alpha) / (2 * a);
        x1 = p + q;
        x2 = p - q;
        printf("函数的根为: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
}