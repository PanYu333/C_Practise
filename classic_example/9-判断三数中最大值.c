#include <stdio.h>

int main()
{
    int a, b, c, result;

    printf("请输入三个数: ");
    scanf("%d %d %d", &a, &b, &c);

    result = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("最大值为: %d\n", result);

    return 0;
}