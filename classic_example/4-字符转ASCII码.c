/*
    scanf的enter会存在在缓存区, enter的ASCII为10
*/

#include <stdio.h>

#define MAX_STR_LENGTH 100

void single_ASCII();
void several_ASCII();

int main()
{
    single_ASCII();
    several_ASCII();
    return 0;
}

/*输出单个字符*/
void single_ASCII()
{
    char c, enter;
    printf("请输入一个字符: ");
    scanf("%c", &c);            //字符类型输入按下回车，会存到缓存区
    enter = getchar();                  //用getchar()吃掉这个字符

    printf("%c的ASCII码值为 %d\n", c, c);
    printf("回车ASCII码值为 %d\n", enter);
}

/*输出多个字符的ASCII*/
void several_ASCII()
{
    char s[MAX_STR_LENGTH];     //定义字符数组

    printf("请输入一个小于%d字符串: ", MAX_STR_LENGTH);
    scanf("%s", &s);
    
    for(int i = 0; s[i] != '\0'; i++)
    {
        printf("%c的ASCII码值为%3d\n", s[i], s[i]);
    }
}