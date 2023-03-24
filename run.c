#include<stdio.h>
#include<stdlib.h>

#define N 3

struct Work
    {
        int num;
        char name[20];
        float sall;
    };

struct Work* Data_Input(struct Work Worker1[]);

void Data_Output(struct Work Worker2[]);
void main()
{
    int i;
    float totle=0,avg=0;
    struct Work Worker[N],*t;   //做一个指针去接受地址
    t = Data_Input(Worker);     //接收地址
    Data_Output(Worker);
    for(i=0;i<N;i++)
    {
        totle=totle+(*(t+i)).sall;  //用i来移位操作的地址
    }
    avg=totle/N;
    printf("平均销售额=%.2f",avg);
}


/*做个解释，因为数组的传递都是指针传递，所以如果想最后返回一个结构体数组是不能直接返回数组元素的，
你可以返回数组变量的首地址，所以我们最后返回的是一个指针（地址），这个指针指向的东西我们已经操作过了
在这个Data_input中我们是把输入的数据复制了一份放到temp中，所以可以根据temp的地址来操作
然后在主程序里面用一个同样的类型指针去接受，接受这个地址*/


struct Work* Data_Input(struct Work Worker1[])
{
    int i;
    static struct Work temp[N];     //因为返回得是指针，所以局部变量必须是静态的
                                    //动态的局部变量在函数调用后自动销毁，也就不存在其地址了 
   
    for(i=0;i<3;i++)
    {
        printf("输入第%d位职工的工号、姓名、销售额\n",i+1);
        scanf("%d %s %f",&Worker1[i].num,&Worker1[i].name,&Worker1[i].sall);
    }

    for(i=0; i<N; i++)             //对数组不能直接temp[N] = worker1[N]
    {
        temp[i] = Worker1[i];
    }

    return temp;

}

void Data_Output(struct Work Worker2[])
{
    int i;
    for(i=0;i<N;i++)
    printf("工号：%d 姓名：%s 打印机销售额：%f\n",Worker2[i].num,Worker2[i].name,Worker2[i].sall);
}