#include <iostream>
#include <string>
#include <cstring> // For strlen and strcpy
using namespace std;

struct Node
{
    char data;
    Node *next;
};

void push(char data, Node *&top)
{
    Node *temp = new Node; // Use new for memory allocation
    temp->data = data;
    temp->next = top;
    top = temp;
}

char pop(Node *&top)
{
    if (top == nullptr)
    {
        return '\0';
    }

    Node *temp = top;
    char result = temp->data;
    top = top->next;
    delete temp; // Free the memory after popping the element
    return result;
}

int isOperator(char a)
{
    if (a == '(')
    {
        return 4;
    }
    else if (a == ')')
    {
        return 3;
    }

    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    return 0;
}

string postFix(string infix, Node *&top)
{
    // Get the length of the input infix string
    int len = infix.length();
    string postfix = "";

    for (int i = 0; i < len; i++)
    {
        int res = isOperator(infix[i]);

        // if res is equal to '(' then directly push it into the stack
        if (res == 4)
        {
            push(infix[i], top);
            continue;
        }

        else if (res == 3) // closing bracket ')'
        {
            while (top->data != '(' && top != nullptr)
            {
                postfix += pop(top);
            }
            // to remove '('
            pop(top);
        }

        // if res is equal to ')' then pop the operators in stack until it is equal to

        else if (res == 0)
        {
            postfix += infix[i];
        }
        else
        {
            // Pop operators with greater or equal precedence
            while (top != nullptr && isOperator(infix[i]) <= isOperator(top->data) && top->data != '(')
            {
                postfix += pop(top);
            }
            push(infix[i], top);
        }
    }

    while (top != nullptr)
    {
        postfix += pop(top);
    }

    return postfix;
}

int main()
{
    Node *top = nullptr;
    string str = "(a+b)*(c-d)";
    cout << "POSTFIX STRING : " << postFix(str, top);
    return 0;
}
