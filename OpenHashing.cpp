#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next = nullptr;
};

int hashSize = 7;
Node **HT = new Node *[hashSize];

// Number of elements in hash table
int n = 0;

// function to initialize array with zeros
void initializeHT(Node **&HT, int size)
{
    for (int i = 0; i < size; i++)
    {
        HT[i] = nullptr; // Initialize all pointers to nullptr
    }
}

// Finding the next prime number to determine new hash size
int findNextPrime()
{
    int nextPrime = hashSize * 2;
    bool flag = false;

    while (!flag)
    {
        flag = true;
        for (int i = 2; i <= nextPrime / 2; i++)
        {
            if (nextPrime % i == 0)
            {
                flag = false; // It's not prime
                break;
            }
        }
        if (!flag)
        {
            nextPrime++;
        }
    }
    return nextPrime;
}

void increaseSize()
{
    // Create new hash table with a larger size
    int newHashSize = findNextPrime();
    Node **newHT = new Node *[newHashSize];

    // Initialize the new hash table with nullptr
    initializeHT(newHT, newHashSize);

    // Copy the values from the old hash table to the new one
    for (int i = 0; i < hashSize; i++)
    {
        if (HT[i] != nullptr)
        {
            // Taking the first Node at index i
            Node *current = HT[i];

            // Loop through the chain and rehash each node into the new table
            while (current != nullptr)
            {
                int HI = current->data % newHashSize;
                Node *temp = new Node;
                temp->data = current->data;

                // If new hash index is empty, insert the new node
                if (newHT[HI] == nullptr)
                {
                    newHT[HI] = temp;
                }
                else
                {
                    // Append at the end of the chain for that index
                    Node *curr = newHT[HI];
                    while (curr->next != nullptr)
                    {
                        curr = curr->next;
                    }
                    curr->next = temp;
                }

                // Move to the next node in the old chain
                current = current->next;
            }
        }
    }

    // Update the hash table with the new one
    HT = newHT;
    hashSize = newHashSize;
}


bool contains(int key)
{
    int HI = key % hashSize;
    if (HT[HI] == nullptr)
    {
        return false;
    }
    else
    {
        Node *current = HT[HI];
        while (current != nullptr)
        {
            if (current->data == key)
            {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

void insert(int key)
{
    // Check if the key already exists in the hash table
    if (contains(key))
    {
        cout << "Duplicate indexing are not allowed";
        return;
    }

    // calculating hash index
    int HI = key % hashSize;

    Node *temp = new Node;
    temp->data = key;

    // if hash index is null
    if (HT[HI] == nullptr)
    {
        HT[HI] = temp;
    }
    else
    {
        // appending at the last of that particular index
        Node *current = HT[HI];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
    }

    // updating number of elements
    n++;

    // Update the global load factor after each insertion
    double loadFactor = (double)n / hashSize;

    // If load factor exceeds 0.5, increase the size of the hash table
    if (loadFactor > 0.5)
    {
        increaseSize();
    }
}

// printing the array
void printArr()
{
    for (int i = 0; i < hashSize; i++)
    {
        Node *current = HT[i];
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
}

int main()
{
    initializeHT(HT, hashSize);
    insert(7);
    insert(21);
    insert(22);
    insert(23);
    insert(24);
    insert(25);

    printArr();
    return 0;
}