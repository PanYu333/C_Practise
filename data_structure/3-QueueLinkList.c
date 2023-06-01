/*Queue - Linked List implementation*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

char IsEmpty();
void Enqueue(int x);
int Dequeue();
int Front();
void Print();

// Two glboal variables to store address of front and rear nodes. 
Node *front = NULL;
Node *rear = NULL;

int main()
{
    // Printing elements in Queue after each Enqueue or Dequeue
    Dequeue();  Print();
    Enqueue(0); Print(); 
	Enqueue(5); Print();
	Enqueue(2); Print();
	Dequeue();  Print();
	Enqueue(0); Print();
}

char IsEmpty() {
    if (rear == NULL)
        return 1;
    return 0;
}

void Enqueue(int x) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (IsEmpty())
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int Dequeue() {
    Node *head1 = front;
    if (IsEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    if (front == rear)
        front = rear = NULL;
    else
    {
        front = front->next;
    }
    free(head1);

    return front->data;
}

int Front() {
	if(front == NULL) {
		printf("Queue is empty.\n");
		return -1;
	}
	return front->data;
}

void Print() {
	Node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

