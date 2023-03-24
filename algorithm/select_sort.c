#include <stdio.h>

void swap(int *a, int *b);
void select_sort(int *arr, int len);

int main()
{
    int i;
    int arr[] = { 22, 34, 3, -32, 82, 55, 89, -50, 37, -5, 64, 35, 9, 70, 0 };
    int len = sizeof(arr) / sizeof(*arr);

    select_sort(arr, len);

    printf("��С����ѡ��������˳��Ϊ: \n");

    for(i=0; i<len; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;

}

/*��С����ѡ������ arrΪ�������飬 lenΪ���ݳ���*/
void select_sort(int *arr, int len)
{
    int i, j, min;

    for(i=0; i<len-1; i++)
    {
        min = i;
        for(j=i+1; j<len; j++)
        {
            if(arr[j] < arr[min])   //��С��������
            {
                min = j;        //�����Сֵ��λ��
            }
        }
        if(min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }
}

/*������������*/
void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}