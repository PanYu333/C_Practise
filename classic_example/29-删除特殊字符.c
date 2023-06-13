/**
 * 示例:
 * 输入一个字符串: run4#$1oob
 * 输出: runoob
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j;
    char str[100];
    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if((str[i]>='a'&&str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
            continue;
        for (j = i; str[j] != '\0'; j++) {
            str[j] = str[j + 1];
        }
        i--;    // 经过for循环str[i]已被更新
    }
    printf("输出: ");
    puts(str);
    return 0;
}
