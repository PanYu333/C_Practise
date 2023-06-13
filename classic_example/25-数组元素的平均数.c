#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {5, 2, 0, 1, 3, 1, 4, 1};
    int length = *(&arr + 1) - arr;     // 指针的指针
    float result = 0;
    for (int i = 0; i < length; ++i) {
        result += arr[i];
    }
    result /= length;
    printf("The average is: %.2f\n", result);

    return 0;
}