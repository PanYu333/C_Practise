#include <stdio.h>

void swap(int *a, int *b);
void select_sort(int *arr, int len);

int main()
{
    int i;
    int arr[] = { 22, 34, 3, -32, 82, 55, 89, -50, 37, -5, 64, 35, 9, 70, 0 };
    int len = sizeof(arr) / sizeof(*arr);

    select_sort(arr, len);

    printf("选择排序后的顺序为: \n");

    for(i=0; i<len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

/*选择排序从小到大，arr为输入数组， len为数组长度*/
void select_sort(int *arr, int len)
{
    int i, j, min;

    for(i=0; i<len-1; i++)
    {
        min = i;
        for(j=i+1; j<len; j++)
        {
            if(arr[j] < arr[min])   //找到目标最小值
            {
                min = j;        //记录最小值
            }
        }
        if(min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }
}

/*交换两数*/
void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}