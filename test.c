#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void bubble_sort(int *arr, int len);

int main()
{
    int arr[] = {1, 2,3};
    printf("%p\n", (arr+1));
    printf("我的%d", 2 % 14);
    return 0;
}

void bubble_sort(int *arr, int len)
{
    int i, j;

    for(i = 0; i < len-1; i++)
    {
        for(j = 0; j < len-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                arr[j+1] = arr[j] + arr[j+1];
                arr[j] = arr[j+1] - arr[j];
                arr[j+1] = arr[j+1] - arr[j];
            }
        }
    }

}
