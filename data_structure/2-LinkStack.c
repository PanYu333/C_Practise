/**
 * This is an example of link stack.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Push(int x);
void Pop();
int Top();
void Print();
char IsEmpty();

Node *top = NULL;   //global variable,it means empty link stack

int main()
{
    Push(5); Print();
    Push(2); Print();
    Push(0); Print();
    Push(1); Print();
    Pop();   Print();

    int a = Top();
    char b = IsEmpty();
    printf("\nNow, the top is: %d\n", a);
    printf("Now, the stack is empty? : %s\n", b == 1 ? "True" : "False");

    return 0;
}

/*Push operation to insert an element on top of stack. */
void Push(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

/*Pop operation to remove an element from top of stack.*/
void Pop()
{
    Node *top1 = top;
    if (top == NULL)
        return;
    top = top->next;
    free(top1);
}

/*Top operation to return element at top of stack.*/
int Top()
{

    return top->data;
}

/*Check the stack is empty or not.*/
char IsEmpty()
{
    if (top != NULL)
        return 0;
    else
        return 1;
}

void Print()
{
    Node *head = top;
    printf("The Stack: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
