/**
 * 以栈的方式动态生成数组，然后计算数组元素的标准差。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *GetArray(int n);
float calculateSD(int *arr, int len);

int main() 
{
    int n;
    printf("Please input the size of an array: ");
    scanf("%d", &n);

    int *arr = GetArray(n);
    float sd = calculateSD(arr, n);
    printf("The standard deviation is: %.2f", sd);
}

int* GetArray(int n) {
    int *arr = (int *)malloc(n * sizeof(int));

    printf("Please input the number of the array: \n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

float calculateSD(int *arr, int len) {
    int i;
    float mean = 0, sd = 0;

    for (i = 0; i < len; ++i) {
        mean += arr[i];
    }
    mean /= len;

    for (i = 0; i < len; ++i) {
        sd += pow(arr[i] - mean, 2);
    }
    return sqrt(sd / len);
}