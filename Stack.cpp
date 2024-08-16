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
    delete temp;  // Free the memory after popping the element
    return result;
}

int isOperator(char a)
{
    if (a == '*' || a == '/')
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
        if (res == 0)
        {
            postfix += infix[i];
        }
        else
        {
            if (top == nullptr)
            {
                push(infix[i], top);
            }
            else
            {
                char val = top->data;
                if (infix[i] == '+' || infix[i] == '-')
                {
                    val = pop(top);
                    while (val != '\0')
                    {
                        postfix += val;
                        val = pop(top);
                    }
                    push(infix[i], top);
                }
                else if (infix[i] == '*' || infix[i] == '/')
                {
                    val = pop(top);
                    while (val != '\0' && val != '+' && val != '-')
                    {
                        postfix += val;
                        val = pop(top);
                    }
                    if (val != '\0')
                    {
                        push(val, top);  // Put the popped operator back if it's lower precedence
                    }
                    push(infix[i], top);
                }
            }
        }
    }

    // Pop all remaining operators in the stack
    char val = pop(top);
    while (val != '\0')
    {
        postfix += val;
        val = pop(top);
    }

    return postfix;
}

int main()
{
    Node *top = nullptr;
    string str = "a+b*c-d";
    cout << "POSTFIX STRING : " << postFix(str, top);
    return 0;
}
