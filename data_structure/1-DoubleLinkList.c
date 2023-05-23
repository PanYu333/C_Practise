/**
 * This is an example of double link list.
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *GetNewNode(int x);
void InsertAtHead(int x);
void InsertAtTail(int x);
void Print();
void ReversePrint();

Node *head = NULL;

int main()
{
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtTail(0); Print(); ReversePrint();
    InsertAtHead(5); Print(); ReversePrint();
    return 0;
}

/*Create a new node*/
Node* GetNewNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

/*Insert a node to head*/
void InsertAtHead(int x)
{
    Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

/*Insert a node to tail*/
void InsertAtTail(int x)
{
    Node *newNode = GetNewNode(x);
    Node *head1 = head;     // head1 search the tail node.

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (head1->next != NULL)
    {
        head1 = head1->next;
    }
    head1->next = newNode;
    newNode->prev = head1;

}

/*forward printing*/
void Print()
{
    Node *head1 = head;
    printf("Forward: ");

    while (head1 != NULL)
    {
        printf("%d ", head1->data);
        head1 = head1->next;
    }
    printf("\n");
}

/*Reverse printing*/
void ReversePrint()
{
    Node *head2 = head;     // head2 search the tail node.
    if (head2 == NULL)
        return;
    while (head2->next != NULL)
    {
        head2 = head2->next;
    }

    printf("Reverse: ");
    while (head2 != NULL)
    {
        printf("%d ", head2->data);
        head2 = head2->prev;
    }
    printf("\n");
}