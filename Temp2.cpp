#include <iostream>
using namespace std;

/* struct Queue
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

*/

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front = nullptr; // Corrected front pointer declaration
    Node *rear = nullptr;  // Rear pointer to track the last node

    // Enqueue operation (add element at the rear)
    void enqueue(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;

        if (front == nullptr) // If queue is empty, both front and rear point to the new node
        {
            front = temp;
        }
        else
        {
            rear->next = temp; // Link the new node to the rear
        }
        rear = temp; // Update rear to the new node
    }

    // Dequeue operation (remove element from the front)
    int dequeue()
    {
        if (front == nullptr) // Check if queue is empty
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        int result = front->data; // Get data from the front node
        Node *temp = front;
        front = front->next; // Move front to the next node
        delete temp; // Free the memory of the dequeued node

        if (front == nullptr) // If the queue becomes empty, rear should also be nullptr
        {
            rear = nullptr;
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
