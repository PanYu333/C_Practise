#include <stdio.h>

//ð�������㷨
//��ĩβ��ʼ���򣬴�С����

void bubble_sort(int *arr, int len);
int main()
{
    int i;
    int arr[] = { 22, 34, 3, -32, 82, 55, 89, -50, 37, -5, 64, 35, 9, 70, 0 };
    int len = sizeof(arr) / sizeof(*arr);

    bubble_sort(arr, len);
    printf("��С����ð��������˳��Ϊ: \n");

    for(i=0; i<len; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}

/*ð�������С����arrΪ�������飬lenΪ���ݳ���*/
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