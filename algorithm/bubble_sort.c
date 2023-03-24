#include <stdio.h>

//冒泡排序算法
//从末尾开始排序，从小到大

void bubble_sort(int *arr, int len);
int main()
{
    int i;
    int arr[] = { 22, 34, 3, -32, 82, 55, 89, -50, 37, -5, 64, 35, 9, 70, 0 };
    int len = sizeof(arr) / sizeof(*arr);

    bubble_sort(arr, len);
    printf("从小到大冒泡排序后的顺序为: \n");

    for(i=0; i<len; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}

/*冒泡排序从小到大，arr为输入数组，len为数据长度*/
void bubble_sort(int *arr, int len)
{
    int i, j, temp;

    for(i=0; i<len-1; i++)
    {
        for(j=0; j<len-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}