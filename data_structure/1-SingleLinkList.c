/**
 * This is an example of Single Link List.
 * function: insert; delete; print;
 */

# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;


void Insert(int data, int addr);
void Delete(int addr);
void Print();

Node *head; // global
int main()
{
    head = NULL;
    Insert(0, 1);   // 0
    Insert(1, 2);   // 0 1
    Insert(1, 3);   // 0 1 1
    Insert(5, 1);   // 5 0 1 1
    Insert(2, 2);   // 5 2 0 1 1
    Print();

    Delete(2);      // 5 0 1 1
    Delete(1);      // 5 1 1
    Print();
}

/*Insert nodes anywhere*/
void Insert(int data, int addr)
{
    Node *temp = (Node *)malloc(sizeof(Node)); // create a node
    temp->data = data;
    temp->next = NULL;

    if (addr == 1)  // special situation
    {
        temp->next = head;   
        head = temp;
        return;
    }

    Node *head1; // head1 as the node of addr-1
    head1 = head;
    for (int i = 0; i < addr - 2; i++)  // offset
    {
        head1 = head1->next;
    }
    temp->next = head1->next;  // Refactoring links
    head1->next = temp;
}

/*Delete nodes anywhere*/
void Delete(int addr)
{
    Node *head1 = head;
    if (addr == 1)
    {
        head = head1->next;
        free(head1);
        return;
    }
    while (addr-- > 2)      // offset
    {
        head1 = head1->next;
    }

    Node *head2 = head1->next;  // Refactoring links
    head1->next = head2->next;  // head1,head2 as the node of addr-1,addr
    free(head2);
}

/*Print Linked List*/
void Print()
{
    Node *temp = head;
    temp = head;
    printf("The List:");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}