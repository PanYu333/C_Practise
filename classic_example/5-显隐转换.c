/**
 * 1.隐式转换：
 *  整形提升：CPU中的ALU运算器总是以(int)型的精度进行，也就是说参与运算的操作数最小也不能小于4个字节的精度，
 *           如若精度小于4个字节该操作数就必须提升成整形的精度。
 *      提升规则：有符号的整形变量，在高位补变量的符号位；无符号的整形变量，高位补0。
 *  算数转换：用来处理大于等于整形的情况。转换方向:int→unsigned int→long int...
 * 
 * 2.显式转换：
 *  强制类型转换：(强制转换的类型)表达式
 *  
*/

#include <stdio.h>

void integer_promate();
void num_convert();
void force_convert();

int main()
{
    integer_promate();
    num_convert();
    force_convert();
    return 0;
}

/*整形提升*/
void integer_promate()
{
    char a = 3, b = 127;    
    char result;

    result = a + b;         //a + b = 00000000_00000000_00000000_10000010,(-126的补码)
                            //然后截取后八位,整形提升,11111110,转换成十进制

    printf("a + b = %d\n", result);
}

/*算数转换*/
void num_convert()
{
    int i = -1;
    if(i < sizeof(i))       //sizeof返回类型是unsigned, 
                            //-1转成uint型非常大1(30个零)1 = 2 ^ 31 + 1
        printf("i < sizeof(i)\n");
    else
        printf("i > sizeof(i)\n");
}

/*强制类型转换*/
void force_convert()
{
    short a = 1234;           //0000_0100_1101_0010
    char b;
    b = (char)a;            //(char), (unsigned char)或者不写，效果都一样
                            //截取为1101_0010,此时为补码，原码为1010_1110 = -46
    printf("强制转换后b = %d\n", b);
}

