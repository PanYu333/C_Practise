#include <stdio.h>
#include <string.h>

void reverseSentence(char *str);

int main()
{
    char str[30];
    printf("请输入一个字符串：");
    scanf("%s", str);

    printf("翻转之后的字符为：");
    reverseSentence(str);
}

void reverseSentence(char* str)
{
    if (*str == '\0')
        return;
    reverseSentence(str + 1);
    printf("%c", *str);
}