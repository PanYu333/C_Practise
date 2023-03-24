/**
 * 除了 %2 = 0方法外，奇数的二进制都是以1结尾
*/

#include <stdio.h>

int main()
{
    int number;

    printf("请输入一个数: ");
    scanf("%d", &number);
    
    if(number & 1)
        printf("%d是一个奇数\n", number);
    else
        printf("%d是一个偶数\n", number);

}