/**
 * 矩阵A:(m,k), 矩阵B:(k, n) 
 * 相乘得矩阵C: (m, n);
 * 矩阵A转置得: transpose: (k,m)
 * 用函数指针重构函数功能: Insert or Print?
 */

#include <stdio.h>
#include <stdlib.h>

struct Matrixs
{
    int elements[20][20];
    int row;
    int column;
} A, B, C, transpose;

void Insert(struct Matrixs *arr, int i, int j);
void Print(struct Matrixs *arr, int i, int j);
void MatrixData(struct Matrixs *arr, void (*func)(struct Matrixs *, int, int));
void Transpose(struct Matrixs *A, struct Matrixs *transpose);

int main() {
    int i, j, k;
    printf("Input the row of matrix A: ");
    scanf("%d", &A.row);
    printf("Input the column of matrix A: ");
    scanf("%d", &A.column);
    printf("Input the column of matrix B: ");
    scanf("%d", &B.column);
    B.row = A.column;
    C.row = A.row;
    C.column = B.column;

    printf("Enter the data of A:\n");
    MatrixData(&A, Insert);

    printf("Enter the data of B:\n");
    MatrixData(&B, Insert);
    
    for (i = 0; i < A.row; ++i) {
        for (j = 0; j < B.column; ++j) {
            for (k = 0; k < B.row; ++k) {
                if (k == 0)
                    C.elements[i][j] = 0;
                C.elements[i][j] += A.elements[i][k] * B.elements[k][j];
                
            }
        }
    }

    printf("Matrix A: \n");
    MatrixData(&A, Print);
    printf("\n");

    printf("Matrix B: \n");
    MatrixData(&B, Print);
    printf("\n");

    printf("Matrix C = A @ B: \n");
    MatrixData(&C, Print);
    printf("\n");

    transpose.row = A.column;
    transpose.column = A.row;
    Transpose(&A, &transpose);
    printf("Matrix transpose = AT: \n");
    MatrixData(&transpose, Print);
    printf("\n");

    return 0;
}

void Insert(struct Matrixs *arr, int i, int j) {
    printf("a%d%d: ", i + 1, j + 1);
    scanf("%d", &arr->elements[i][j]);
}

void Print(struct Matrixs *arr, int i, int j) {
    printf("%3d", arr->elements[i][j]);
}

/*矩阵插入或打印*/
void MatrixData(struct Matrixs *arr, void (*func)(struct Matrixs*, int, int)) {
    int i, j;
    for (i = 0; i < arr->row; ++i) {
        for (j = 0; j < arr->column; ++j) {
            func(arr, i, j);
        }
        printf("\n");
    }
}

/*矩阵转置*/
void Transpose(struct Matrixs *A, struct Matrixs *transpose) {
    int i, j;
    for (i = 0; i < A->row; ++i) {
        for (j = 0; j < A->column; ++j) {
            transpose->elements[j][i] = A->elements[i][j];
        }
    }
}