/**
 * This is an example of using stack to reverse a link list.
 * You can also use stacks previously written in C language
 * to achieve inversion.
*/
#include <iostream>
#include<string>
#include <stack>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void Reverse();
void InsertAtTail(int x);
void Print();

Node *head = NULL;

int main()
{
    InsertAtTail(5);
    InsertAtTail(2);
    InsertAtTail(0);
    Print();
    Reverse();
    Print();

    return 0;
}

/*Reverse a link list using a stack*/
void Reverse()
{
    Node *head1 = head;
    stack<Node *> S;
    while (head1 != NULL)   // stack pushing
    {
        S.push(head1);
        head1 = head1->next;
    }

    head = S.top();     // head and head1 are all point to stack header
    head1 = head;
    S.pop();

    while (! S.empty()) // head1 Concatenate all content
    {
        head1->next = S.top();
        S.pop();
        head1 = head1->next;
    }
    // after while statement, head1->next doesn't change
    // So let it point to NULL.
    head1->next = NULL;
}


void InsertAtTail(int x)
{
    Node *head1 = head;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (head1 == NULL)
    {
        head = temp;
        return;
    }
    while (head1->next != NULL)
    {
        head1 = head1->next;
    }
    head1->next = temp;
}

/*Print Linked List*/
void Print()
{
    Node *temp = head;
    printf("The List:");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}