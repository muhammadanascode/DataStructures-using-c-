#include <iostream>
using namespace std;

// Binary heap length
const int n = 10;

// heap tree
int BH[n];

// current index . starting with 1
int idx = 1;

// initializing array with -1
void initialize()
{
    for (int i = 0; i < n; i++)
    {
        BH[i] = -1;
    }
}

// inserting data into the heap array
void enqueue(int data)
{
    if (idx >= n) {
        cout << "Heap is full!" << endl;
        return;
    }

    BH[idx] = data;
    int i = idx;
    while (i > 1 && BH[i] > BH[i / 2])
    {
        // swapping
        int temp = BH[i];
        BH[i] = BH[i / 2];
        BH[i / 2] = temp;

        i = i / 2;
    }
    idx++;
}

// dequeue or extract max
int dequeue()
{
    if (idx <= 1) // No elements to dequeue
    {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int result = BH[1]; // root element (max element)
    BH[1] = BH[idx - 1]; // replace root with the last element
    BH[idx - 1] = -1; // reset the last element
    idx--; // decrease heap size

    // Reheapify from the root
    int N = 1;
    while (N * 2 < idx) // ensure we don't go beyond heap size
    {
        int left = N * 2;
        int right = N * 2 + 1;

        // Find the larger child
        int greater = left;
        if (right < idx && BH[right] > BH[left])
        {
            greater = right;
        }

        // Swap if parent is smaller than the larger child
        if (BH[N] < BH[greater])
        {
            int temp = BH[N];
            BH[N] = BH[greater];
            BH[greater] = temp;
            N = greater; // continue heapifying down
        }
        else
        {
            break; // heap property restored
        }
    }

    return result;
}

// print heap tree
void print()
{
    for (int i = 1; i < idx; ++i) // Printing only the valid elements in the heap
    {
        cout << BH[i] << endl;
    }
}

int main()
{
    initialize();
    enqueue(24);
    enqueue(37);
    enqueue(17);
    enqueue(69);
    enqueue(42);
    enqueue(77);
    enqueue(98);

    cout << "Dequeue: " << dequeue() << endl;
    cout << "Dequeue: " << dequeue() << endl;
    cout << "Dequeue: " << dequeue() << endl;

    print();

    return 0;
}
