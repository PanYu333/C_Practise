/**
 * This is an example of Link List.
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

Node *head; //global
int main()
{
    head = NULL;
    Insert(0, 1);   // 0
    Insert(1, 2);   // 0 1
    Insert(1, 3);   // 0 1 1
    Insert(5, 1);   // 5 0 1 1
    Insert(2, 2);   // 5 2 0 1 1
    Print();

    Delete(2);      //5 0 1 1
    Delete(1);      //5 1 1
    Print();
}

/*Insert nodes anywhere*/
void Insert(int data, int addr)
{
    Node *temp1 = (Node *)malloc(sizeof(Node)); //create a node
    temp1->data = data;
    temp1->next = NULL;

    if (addr == 1)  // special situation
    {
        temp1->next = head;   
        head = temp1;
        return;
    }

    Node *head1; // head1 as the node of addr-1
    head1 = head;
    for (int i = 0; i < addr - 2; i++)  //offset
    {
        head1 = head1->next;
    }
    temp1->next = head1->next;  //Refactoring links
    head1->next = temp1;
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
    while (addr-- > 2)      //offset
    {
        head1 = head1->next;
    }

    Node *head2 = head1->next;  //Refactoring links
    head1->next = head2->next;
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