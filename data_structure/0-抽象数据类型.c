/**
 * 定义结构体变量：复数类型。 并实现计算复数的加减乘除
 * 实例：
 *  z1 = (8+6j)
 *  z2 = (4+3j)
 *  z = z1 * z2 / (z1 + z2)
 *  最后输出z的值
*/

#include <stdio.h>

//定义复数的抽象类型
typedef struct{
    float realpart;
    float imagepart;
} Complex;

void assign(Complex *A, float real, float image);
void add(Complex *C, Complex A, Complex B);
void sub(Complex *C, Complex A, Complex B);
void mul(Complex *C, Complex A, Complex B);
void div(Complex *C, Complex A, Complex B);

int main()
{
    Complex z1, z2, z3, z4, z;
    // float realpart, imagepart;
    assign(&z1, 8.0, 6.0);
    assign(&z2, 4.0, 3.0);
    add(&z3, z1, z2);
    mul(&z4, z1, z2);

    if (z3.realpart && z3.imagepart)
        div(&z, z4, z3);
    printf("result: z.realpart = %.2f, z.imagepart = %.2f\n", z.realpart, z.imagepart);
    return 0;
}


/*生成复数数据*/
void assign(Complex *A, float real, float image)
{
    A->realpart = real;
    A->imagepart = image;
}

/*复数加法*/
void add(Complex *C, Complex A, Complex B)
{
    C->realpart = A.realpart + B.realpart;
    C->imagepart = A.imagepart + B.imagepart;
}

/*复数减法*/
void sub(Complex *C, Complex A, Complex B)
{
    C->realpart = A.realpart - B.realpart;
    C->imagepart = A.imagepart - B.imagepart;
}

/*复数乘法*/
void mul(Complex *C, Complex A, Complex B)
{
    C->realpart = A.realpart * B.realpart - A.imagepart * B.imagepart;
    C->imagepart = A.realpart * B.imagepart + A.imagepart * B.realpart;
}

/*复数除法*/
void div(Complex *C, Complex A, Complex B)
{
    float denominator;

    denominator = B.realpart * B.realpart + B.imagepart * B.imagepart;

    C->realpart = (A.realpart * B.realpart + A.imagepart * B.imagepart) / denominator;
    C->imagepart = (- A.realpart * B.imagepart + A.imagepart * B.realpart) / denominator;
}