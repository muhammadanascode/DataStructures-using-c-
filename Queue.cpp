#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void enqueue(int data, Node *&front, Node *&rear)
{
    Node *temp = new Node;
    temp->data = data;
    if (front == nullptr)
    {
        front = temp;
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
}

int dequeue(Node *&front, Node *&rear)
{
    if (front == nullptr)
    {
        return -1;
    }

    int result = front->data;
    front = front->next;

    if (front == nullptr)
    {
        rear = nullptr ;
    }
    cout<<result<<endl ;
    return result;
}

int main()
{
    Node *front = nullptr;
    Node *rear = nullptr;

    enqueue(4, front, rear);
    enqueue(3, front, rear);
    enqueue(2, front, rear);

    dequeue(front, rear);
    dequeue(front, rear);
    dequeue(front, rear);

    return 0 ;
}