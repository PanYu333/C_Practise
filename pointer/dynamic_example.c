/**
 * 这是一个关于动态内存的例子
*/

# include <stdio.h>
# include <stdlib.h>

int *use_malloc(int n);
int *use_calloc(int n);
int *use_realloc(int *A, int n);

int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    // int A[n];   //编译报错，运行期间必须事先知道数组的大小，方括号内的值不可为变量
    int *A;

    A = use_malloc(n);
    // A = use_calloc(n);
    A = use_realloc(A, n);     //扩展为两倍动态内存

    for (int i = 0; i < 2 * n; i++)
    {
        printf("%d ", A[i]);
    }
}

int* use_malloc(int n)
{
    int *p1 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)     //初始化，否则为垃圾值
    {
        p1[i] = i + 1;
    }

    // free(p1);       //释放内存
    // *p1 = 6;        //但p1依然指向该地址，这是指针的危险地方
    // printf("%d\n", p1[0]);

    // p1 = NULL;      //应该调整指针指向NULL

    return p1;
}

int* use_calloc(int n)
{
    int *p2 = (int *)calloc(n, sizeof(int));
    return p2;
}

int* use_realloc(int *A, int n)
{
    int *p = (int *)realloc(A, 0 * n * sizeof(int));    
    printf("原来的地址:%d, 新的地址:%d\n", A, p);   //是否分配新的地址
    return p;
}