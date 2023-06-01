/* Queue - Circular Array implementation in C++*/

#include <iostream>
using namespace std;

# define MAXSIZE 101

/*Creating a class named Queue.*/
class Queue
{
    private:
        int A[MAXSIZE];
        int front, rear;

    public:
        Queue()
        {
            front = -1;
            rear = -1;
        }

        bool IsEmpty()
        {
            return (front == -1 && rear == -1);
        }

        bool IsFull()
        {
            return (rear + 1) % MAXSIZE == front;
        }

        void Enqueue(int x)
        {
            if (IsEmpty())
                front = rear = 0;
            else if (IsFull())
            {
                cout << "Queue is full.\n";
                return;
            }
            else
            {
                rear = (rear + 1) % MAXSIZE;
            }
            A[rear] = x;
        }

        void Dequeue()
        {
            cout << "Dequeuing...\n";
            if (IsEmpty())
            {   cout << "Queue don't have element.\n";
                return;
            }
            else if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % MAXSIZE;
            cout << "Dequeue Complete.\n";
        }

        int Front()
        {
            if (front == -1)
            {
                cout << "Can't return front from empty queue.\n";
                return -1;
            }
            return A[front];
        }

        void Print()
        {
            if (IsEmpty())
                return;
            int count = (rear + MAXSIZE - front) % MAXSIZE + 1;
            cout << "\nQueue: ";
            for (int i = 0; i < count; i++)
            {
                int index = (front + i) % MAXSIZE;
                cout << A[index] << ' ';
            }
            cout << "\n";
        }
};

int main()
{
    Queue Q;
    Q.Dequeue(); Q.Print();
    Q.Enqueue(0); Q.Print();
    Q.Enqueue(5); Q.Print();
    Q.Enqueue(2); Q.Print();
    Q.Enqueue(0); Q.Print();
    Q.Dequeue(); Q.Print();
}