#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *LN = nullptr;
    Node *RN = nullptr;
    int height;
};

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->LN);
    cout << root->data << " ";
    inOrder(root->RN);
}

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
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
    cout << root->data << " ";
}

int getHeight(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int balancedFactor(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int val = getHeight(node->LN) - getHeight(node->RN);
    return val;
}

Node *rotateRight(Node *root)
{
    Node *temp = root->LN;
    Node *right = temp->RN;

    temp->RN = root;
    root->LN = right;

    root->height = 1 + max(getHeight(root->LN), getHeight(root->RN));
    temp->height = 1 + max(getHeight(temp->LN), getHeight(temp->RN));

    return temp;
}

Node *rotateLeft(Node *root)
{
    Node *temp = root->RN;
    Node *left = temp->LN;

    temp->LN = root;
    root->RN = left;

    root->height = 1 + max(getHeight(root->LN), getHeight(root->RN));
    temp->height = 1 + max(getHeight(temp->LN), getHeight(temp->RN));

    return temp;
}

Node *createNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->height = 1;
    return temp;
}

Node *insert(int data, Node *root)
{

    if (root == nullptr)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->LN = insert(data, root->LN); // Insert in the left subtree
    }
    else if (data > root->data)
    {
        root->RN = insert(data, root->RN); // Insert in the right subtree
    }
    else
    {
        // Duplicate value, do nothing
        cout << "Duplicate value " << data << " not inserted.\n";
        return root;
    }

    // updating the height of current node
    root->height = 1 + max(getHeight(root->LN), getHeight(root->RN));

    int bf = balancedFactor(root);
    
    // Case 1: left left
    if (bf > 1 && data < root->LN->data)
    {
        return rotateRight(root);
    }

    //Case 2: Right Right
    if (bf<-1 && data>root->RN->data)
    {
        return rotateLeft(root);
    }

    //Case 3: Left Right 
    if (bf>1 && data>root->LN->data)
    {
        root->LN = rotateLeft(root->LN) ;
        return rotateRight(root) ;
    }

    //Case 4 : Right Left
    if (bf<-1 && data<root->RN->data)
    {
        root->RN = rotateRight(root->RN) ;
        return rotateLeft(root) ;
    }
    
    
    return root;
}

int main()
{
    Node *root = nullptr;

    root = insert(7, root);
    root = insert(9, root);
    root = insert(8, root);

    cout << "In-order traversal of the constructed AVL tree is:\n";
    inOrder(root);
    cout << "\n";

    cout << "Pre-order traversal of the constructed AVL tree is:\n";
    preOrder(root);
    cout << "\n";

    cout << "Post-order traversal of the constructed AVL tree is:\n";
    postOrder(root);
    cout << "\n";
    return 0;
}