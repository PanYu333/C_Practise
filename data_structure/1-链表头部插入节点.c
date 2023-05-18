/**
 * 运用指针的指针实现链表头部插入节点
*/

# include <stdio.h>
# include <stdlib.h>

struct Node         //定义链表节点
{
    int data;
    struct Node* next;
};

void Insert(struct Node** PointerToHead, int x);
void Print(struct Node* head);

int main()
{
    struct Node *head = NULL;  // 此时表头为main的局部变量

    int i, n, x;
    printf("How many numbers?");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter a number:");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
    
    return 0;
}

/*在链表头部插入节点*/
void Insert(struct Node **PointerToHead, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *PointerToHead;
    *PointerToHead = temp;
}

/*打印链表数据*/
void Print(struct Node *head)
{
    printf("The data of link is: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}