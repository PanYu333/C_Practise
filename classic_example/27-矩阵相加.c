#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j, row, column, arr1[20][20], arr2[20][20];
    printf("Input the row:");
    scanf("%d", &row);
    printf("Input the column:");
    scanf("%d", &column);

    printf("Enter the data of arr1:\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            printf("a%d%d: ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter the data of arr2:\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            printf("a%d%d: ", i + 1, j + 1);
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("arr1 + arr2 = \n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            arr1[i][j] = arr1[i][j] + arr2[i][j];
            printf("%3d", arr1[i][j]);
        }
        printf("\n");
    }
}