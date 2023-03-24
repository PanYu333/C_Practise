/**
 * strchr(const char *str, char c):
 *  在参数str所指向的字符串中搜索第一次出现字符c（一个无符号字符）的位置;
 *  返回一个指向该字符串中第一次出现的字符的指针，如果字符串中不包含该字符则返回NULL空指针。
 */

#include <stdio.h>  
#include <string.h>

int main()
{
    char c, *vowels = "aeiouAEIOU";
    char *p;

    printf("请输入一个字母: ");
    c = getchar();

    p = strchr(vowels, c);

    printf("%c是%s\n", c, p ? "元音" : "辅音");

    return 0;
}