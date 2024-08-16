#include <iostream>
#include <cstdlib> // Required for malloc
using namespace std;

struct LinkedList
{
    int data;
    LinkedList *next;
};

// Function to append a new node to the linked list
void insertAtFirst(int data, LinkedList *&head)
{
    LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList)); // Allocate memory for new node using malloc
    temp->data = data;                                           // Set the data for the new node
    temp->next = head;                                           // Make the new node point to the current head
    head = temp;                                                 // Update the head to the new node
}

// Function to traverse and print the linked list
void print(LinkedList *head)
{
    LinkedList *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

// function to append a new Node at the end of  list
void append(int data, LinkedList *&head)
{
    LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList)); // allocating memory using malloc
    LinkedList *current = head;                                  // pointer to traverse to the end of list
    temp->data = data;
    temp->next = nullptr;

    // traversing to the last node
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // adding the new Node to the next of last Node
    current->next = temp;
}

// searching Node using key
void search(int key, LinkedList *&head)
{
    LinkedList *current = head;
    bool flag = false;
    while (current->next != nullptr)
    {
        if (current->data == key)
        {
            cout << "Node exists with specific key\n";
            flag = true;
            break;
        }
        current = current->next;
    }

    if (!flag)
    {
        cout << "Node doesn't exists with given key\n";
    }
}

void deleteNode(int key, LinkedList *&head)
{
    if (head != nullptr && head->data == key)
    {
        head = head->next;
        return;
    }

    LinkedList *current = head;
    LinkedList *prev = head;
    bool flag = false;

    while (current != nullptr)
    {
        if (current->data == key)
        {
            prev->next = current->next;
            flag = true;
            cout << "Node  Deleted\n";
            break;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    if (!flag)
    {
        cout << "Node doesn't exists with key\n";
    }
}

int main()
{
    LinkedList *head = nullptr; // Initialize the head pointer to nullptr

    insertAtFirst(5, head);  // Append a node with data 5
    insertAtFirst(10, head); // Append a node with data 10
    insertAtFirst(15, head); // Append a node with data 15
    append(20, head);        // Append a node with data 20
    append(40, head);        // Append a node with data 40
    search(21, head);        // searching node using key
    search(20, head);        // searching node using key
    deleteNode(20, head);    // searching node using key
    deleteNode(25, head);    // searching node using key

    // Traverse and print the linked list
    print(head);

    return 0;
}
