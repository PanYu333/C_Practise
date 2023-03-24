#include <stdio.h>                                                                                
 
int* count_factor(int number, int *len);

int main()
{
    int i;
    int number;
    int len = 0;
    int *arr;
    printf("请输入一个数: ");
    scanf("%d", &number);
    
    arr = count_factor(number, &len);

    printf("该数的公因数有: ");
    while (len-- != 0)
    {   
        printf("%d ", *arr++);
    }
    
    return 0;
}

int* count_factor(int number, int *len)
{
    int i;
    static int factor[100] = {};

    for (i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            factor[*len] = i;
            (*len)++;
        }
    }
    return factor;
}        