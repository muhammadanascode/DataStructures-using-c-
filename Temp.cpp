#include <iostream>
using namespace std;

// stack using array

/*
struct Stack
{
    int arr[10];
    int top = -1;

    void push(int data)
    {
        if (top >= 9)
        {
            cout << "Stack overflow";
            return;
        }
        arr[++top] = data;
        return;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow";
            return -1;
        }
        return arr[top--];
    }

};

int
main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
    return 0;
} */

//stack using linked-list
struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *top = nullptr;

    void push(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        int result = top->data;
        top = top->next;
        return result;
    }
};

int
main()
{
    Stack *s  =new Stack ;
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);

    cout << s->pop();
    cout << s->pop();
    cout << s->pop();
    cout << s->pop();

    return 0;
}