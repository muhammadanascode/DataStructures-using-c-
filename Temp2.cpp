#include <iostream>
using namespace std;

struct Queue
{
    int arr[10];
    int front = -1;
    int rear = -1;

    // Enqueue operation
    void enqueue(int data)
    {
        if (rear >= 9)
        {
            cout << "Queue overflow" << endl;
            return;
        }

        if (front == -1) // If the queue is empty, set the front to 0
        {
            front = 0;
        }
        arr[++rear] = data; // Add the element and increment rear
    }

    // Dequeue operation
    int dequeue()
    {
        if (front == -1 || front > rear) // Check if the queue is empty
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        int result = arr[front++]; // Get the front element and increment front

        // If the queue becomes empty after dequeuing, reset the front and rear pointers
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }

        return result;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl; // This will trigger Queue underflow

    return 0;
}
