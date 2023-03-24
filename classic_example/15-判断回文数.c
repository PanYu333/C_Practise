/**
 * 利用求余,除法操作取出每位数, 重构相反序列数判断
*/

#include <stdio.h>

int main()
{
    int n, reminder, originalNumber, reversedNumber;

    printf("请输入一个数：");
    scanf("%d", &n);
    
    originalNumber = n;

    while (n != 0)
    {
        reminder = n % 10;
        reversedNumber = reversedNumber * 10 + reminder;
        n /= 10;
    }

    if (originalNumber != reversedNumber)
        printf("%d不是回文数!\n", originalNumber);
    else
        printf("%d是回文数!\n", originalNumber);

    return 0;
}