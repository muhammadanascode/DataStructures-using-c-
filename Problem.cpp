#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *LN = nullptr;
    Node *RN = nullptr;
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

void insert(int data, Node *&root)
{
    if (root == nullptr)
    {
        Node *temp = new Node;
        temp->data = data;
        root = temp;
        return;
    }

    if (data < root->data)
    {
        insert(data, root->LN); // Insert in the left subtree
    }
    else if (data > root->data)
    {
        insert(data, root->RN); // Insert in the right subtree
    }
    else
    {
        // Duplicate value, do nothing
        cout << "Duplicate value " << data << " not inserted.\n";
        return;
    }
}

// Traversing to right because the right most Node will be maximum
Node *findMax(Node *&root)
{
    // Check if the tree is empty
    if (root == nullptr)
    {
        return nullptr;
    }

    // The rightmost node is maximum
    if (root->RN == nullptr)
    {
        return root;
    }

    return findMax(root->RN);
}

////Traversing to left because the left most Node will be minimum.
Node *findMin(Node *&root)
{
    // Check if the tree is empty
    if (root == nullptr)
    {
        return nullptr;
    }

    // The leftmost node is the minimum
    if (root->LN == nullptr)
    {
        return root;
    }

    return findMin(root->LN);
}

// searching in a binary search tree
bool binarysearch(int key, Node *&root)
{
    if (root == nullptr)
    {
        cout << "Key not found" << endl;
        return false;
    }

    if (root->data == key)
    {
        cout << "Key exists" << endl;
        return true;
    }
    else if (key < root->data)
    {
        return binarysearch(key, root->LN);
    }
    else
    {
        return binarysearch(key, root->RN);
    }
}

void deleteKey(int key, Node *&root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data == key)
    {

        // Case 1:  If it is a leaf node then delete it directly
        if (root->LN == nullptr && root->RN == nullptr)
        {
            delete root;
            root = nullptr;
            return;
        }

        // Case 2:  if the Node having one child
        // 1: Having left childs
        else if (root->RN == nullptr)
        {
            Node *temp = root->LN;
            delete root;
            root = temp;
            return;
        }
        // 2: Having right childs
        else if (root->LN == nullptr)
        {
            Node *temp = root->RN;
            delete root;
            root = temp;
            return;
        }

        // Case 3: Having both left and right childs   //TODO:
        else
        {
            // finding minimm node from root's right
            Node *min = findMin(root->RN);

            // replacing data
            root->data = min->data;

            // Now recursively deleting the minimum node from the right subtree of root node
            deleteKey(root->data, root->RN);
        }
    }

    // finding Node
    else if (key < root->data)
    {
        return deleteKey(key, root->LN);
    }
    else
    {
        return deleteKey(key, root->RN);
    }
}

int main()
{
    Node *root = nullptr;
    insert(100, root);
    insert(50, root);
    insert(30, root);
    insert(60, root);
    insert(40, root);
    insert(45, root);
    insert(35, root);
    insert(150, root);
    insert(130, root);
    insert(120, root);
    insert(175, root);
    insert(160, root);
    insert(165, root);
    insert(162, root);
    insert(166, root);

    deleteKey(150, root);

    cout << "InOrder Traversal: ";
    inOrder(root);
    cout << "\nPreOrder Traversal: ";
    preOrder(root);
    cout << "\nPostOrder Traversal: ";
    postOrder(root);

    return 0;
}
