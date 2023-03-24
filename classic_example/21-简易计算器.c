#include <stdio.h>

int get_option();
void print_result(int option, float num1, float num2, float result);

int main(int argc, int **argv[])
{
    char done = 0;      //继续运算标志位
    int option;
    float num1, num2, result;

    while (!done)
    {
        option = get_option();

        if (option == 0)
            done = 1;
        else
        {
            do
            {
                printf("请输入两个数: ");
                scanf("%f %f", &num1, &num2);

                if (option == 4 && num2 == 0)
                    printf("除数不能为0, 请重新输入！\n");
                else
                {
                    switch (option)
                    {
                        case 1: 
                            result = num1 + num2; break;
                        case 2: 
                            result = num1 - num2; break;
                        case 3: 
                            result = num1 * num2; break;
                        case 4: 
                            result = num1 / num2; break;

                        default:
                            break;
                    }
                    print_result(option, num1, num2, result);
                }
            } while (option == 4 && num2 == 0);
        }
    }
    
    return 0;
}

/*获取功能*/
int get_option()
{
    int option = 0;

    do
    {
        printf("\n ****************");
        printf("\n *    1. 加法   *");
        printf("\n *    2. 减法   *");
        printf("\n *    3. 乘法   *");
        printf("\n *    4. 除法   *");
        printf("\n *    0. 退出   *");
        printf("\n ****************");

        printf("\n请输入您需要的功能: ");
        scanf("%d", &option);
        if (option < 0 || option > 4)
        {
            printf("对不起, 您输入的数字有误, 请重新输入:\n");
        }
    } while (option < 0 || option > 4);

    return option;
}

/*显示结果*/
void print_result(int option, float num1, float num2, float result)
{
    char operator;
    switch (option)
    {
    case 1:  operator= '+'; break;
    case 2:  operator= '-'; break;
    case 3:  operator= '*'; break;
    case 4:  operator= '/'; break;
    default:
        break;
    }

    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
}