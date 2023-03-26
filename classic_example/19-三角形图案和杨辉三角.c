/**
 * 三角形系列,包含杨辉三角
*/

#include <stdio.h>

void show_triangle(int row);
void show_invertriangle(int row);

void pyramid(int row);
void num_pyramid(int row);

void yang_triangle(int row);
void yanghui_angle(int row);

int main()
{
    int i, j, row;

    printf("please input a number: ");
    scanf("%d", &row);

    show_triangle(row);
    show_invertriangle(row);

    pyramid(row);
    num_pyramid(row);

    yang_triangle(row);
    yanghui_angle(row);

    return 0;
}

/*符号三角形*/
void show_triangle(int row)
{
    int i, j;
    printf("\n符号三角形如下: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

/*倒置符号三角形*/
void show_invertriangle(int row)
{
    int i, j;

    printf("\n倒置符号三角形如下: \n");
    for (i = 0; i < row; ++i)
    {
        for (j = row - i; j > 0; --j)
        {
            printf("* ");
        }
        printf("\n");
    }
}

/*符号金字塔*/
void pyramid(int row)
{
    int i, j, space;

    printf("\n符号金字塔如下: \n");

    for (i = 1; i <= row; ++i)
    {
        //打印前置空格
        for (space = 1; space <= row - i; ++space)
        {
            printf("  ");
        }

        //打印2 * - 1个 ‘*’
        int m = 2 * i - 1;
        while (m--)
        {
            printf("* ");
        }

        printf("\n");
    }
}

/*数字金字塔*/
void num_pyramid(int row)
{
    //k记录该行打印的真实数字个数, space记录起初的空格,
    //count记录数字当前位置, count1记录该减去的差值
    int i, j, space, k = 0, count = 0, count1 = 0;

    printf("\n数字金字塔如下: \n");
    for (i = 1; i <= row; i++)
    {
        //打印空格，空格数为row-i
        for (space = 1; space <= row - i; space++)
        {
            printf("  ");
            count++;        
        }

        while (k != 2 * i - 1)
        {
            //判断有没有写到中间位置
            if (count < row)
            {
                printf("%d ", i + k);
                count++;
            }

            //中间位置后准备下降数字
            else    
            {
                count1++;
                printf("%d ", i + k - 2 * count1);
            }
            k++;
        }

        k = count = count1 = 0;
        printf("\n");
    }
}

/*杨辉三角直角板*/
void yang_triangle(int row)
{
    int i, j, space;
    int arr[100][100] = { 0 };

    printf("\n杨辉三角形直角板如下: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < row; j++)
        {
            if (j == 0 || i == j)
                arr[i][j] = 1;

            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}

/*正宗杨辉三角*/
void yanghui_angle(int row)
{
    int i, j, k;
    int arr[10][10] = {0};

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < row; j++)
        {
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (i = 0; i < row; i++)
    {
        for (k = 1; k < row - i; k++)
        {
            printf("  ");
        }

        for (j = 0; j <= i; j++)
        {
            printf("%-4d", arr[i][j]);
        }
        printf("\n");
    }
}

