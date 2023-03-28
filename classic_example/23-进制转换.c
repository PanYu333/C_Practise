/**
 * 进制数的相互转化
*/

#include <stdio.h>
#include <math.h>

long long convertDecimal2Binary(int decimalNumber);
int convertBinary2Decimal(long long binaryNumber);
int convertBinary2Octal(long long binaryNumber);

int main()
{
    int dec_num;          //输入的10进制数
    long long bin_num;    //输入的二进制数，long long占8字节

    printf("请输入一个十进制数：");
    scanf("%d", &dec_num);

    printf("请输入一个二进制数：");
    scanf("%lld", &bin_num);

    printf("%d 转换为二进制后的数值为：%lld\n", dec_num, convertDecimal2Binary(dec_num));
    printf("%lld 转换为十进制后的数值为：%d\n", bin_num, convertBinary2Decimal(bin_num));
    printf("%lld 转换为八进制后的数值为：%d\n", bin_num, convertBinary2Octal(bin_num));

    return 0;
}

/*十进制转2进制*/
long long convertDecimal2Binary(int decimalNumber)
{
    int reminder, i = 0;
    long long result = 0;

    while (decimalNumber)
    {
        reminder = decimalNumber % 2;
        decimalNumber /= 2;
        result += reminder * pow(10, i);
        ++i;
    }
    return result;
}

/*二进制转十进制*/
int convertBinary2Decimal(long long binaryNumber)
{
    int i = 0, result = 0, reminder;
    while (binaryNumber)
    {
        reminder = binaryNumber % 10;
        binaryNumber /= 10;
        result += reminder * pow(2, i);
        ++i;
    }
    return result;
}

/*二进制转八进制*/
int convertBinary2Octal(long long binaryNumber)
{
    int decimalNumber = 0, octalNumber = 0, i = 0;
    while (binaryNumber)
    {
        decimalNumber += (binaryNumber % 10) * pow(2, i);
        binaryNumber /= 10;
        ++i;
    }

    i = 0;
    while (decimalNumber)
    {
        octalNumber += (decimalNumber % 8) * pow(10, i);
        decimalNumber /= 8;
        ++i;
    }

    return octalNumber;
}