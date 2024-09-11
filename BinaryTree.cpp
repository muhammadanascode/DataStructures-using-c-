#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char ch;
    Node *LN = nullptr;
    Node *RN = nullptr;
};

Node *stack[10];
int top = -1;

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->LN);
    cout << root->ch;
    inOrder(root->RN);
}

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->ch;
    preOrder(root->LN);
    preOrder(root->RN);
}

void postOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->LN);
    postOrder(root->RN);
    cout << root->ch;
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

void binaryTree(string postfix, Node *root)
{
    // Get the length of the input infix string
    int len = postfix.length();

    for (int i = 0; i < len; i++)
    {
        // creating new Node
        Node *temp = new Node;
        temp->ch = postfix[i];

        int res = isOperator(postfix[i]);

        if (res == 0) // operand case
        {
            stack[++top] = temp;
        }
        else
        { // operand case

            // Popping elements from stack
            temp->RN = stack[top--];
            temp->LN = stack[top--];
            stack[++top] = temp;
        }
    }

    // assigning top to root
    root = stack[top];
    cout<<"InOrder: " ;
    inOrder(root);
    cout<<"   PreOrder: " ;
    preOrder(root) ;
    cout<<"   PostOrder: " ;
    postOrder(root); 
}

int main()
{
    Node *root = nullptr;
    string str = "ab+cd-*";
    binaryTree(str, root);
     return 0;
}