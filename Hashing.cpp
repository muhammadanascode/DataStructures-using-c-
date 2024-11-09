#include <iostream>
using namespace std;

// Initial hash size and hash table
int hashSize = 7;
int *HT = new int[hashSize];

// Number of elements in hash table
int n = 0;

// Function to initialize array with -1 to indicate empty slots
void initializeArr(int *&arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1; // Use -1 to represent empty slots
    }
}

// Finding the next prime number to determine new hash size
int findNextPrime()
{
    int nextPrime = hashSize * 2;
    bool isPrime = false;

    while (!isPrime)
    {
        isPrime = true;
        for (int i = 2; i <= nextPrime / 2; i++)
        {
            if (nextPrime % i == 0)
            {
                isPrime = false; // It's not prime
                break;
            }
        }
        if (!isPrime)
        {
            nextPrime++;
        }
    }
    return nextPrime;
}

// Increasing the size of the hash table and rehashing elements
void increaseSize()
{
    int newHashSize = findNextPrime();
    int *newHT = new int[newHashSize];

    // Initialize the new hash table with -1
    initializeArr(newHT, newHashSize);

    // Rehash existing elements into the new hash table
    for (int i = 0; i < hashSize; i++)
    {
        if (HT[i] != -1)
        { // Only rehash non-empty slots
            int key = HT[i];
            int newHI = key % newHashSize;

            // Linear probing to find an empty slot
            while (newHT[newHI] != -1)
            {
                newHI = (newHI + 1) % newHashSize;
            }
            newHT[newHI] = key;
        }
    }

    delete[] HT; // Free the old hash table memory
    HT = newHT;
    hashSize = newHashSize;
}

// Checking if the key already exists in the hash table
bool contains(int key)
{
    int HI = key % hashSize;
    while (HT[HI] != -1)
    { // Check until an empty slot
        if (HT[HI] == key)
            return true;
        HI = (HI + 1) % hashSize;
    }
    return false;
}

// Insert a key into the hash table
void insert(int key)
{
    // Check if the key already exists
    if (contains(key))
    {
        cout << "Key " << key << " is already present in the hash table." << endl;
        return;
    }

    int HI = key % hashSize;

    // Linear probing to find an empty slot
    while (HT[HI] != -1)
    {
        HI = (HI + 1) % hashSize;
    }
    HT[HI] = key;
    n++;

    // Update the load factor
    double loadFactor = (double)n / hashSize;

    // Increase the size if the load factor exceeds 0.5
    if (loadFactor > 0.5)
    {
        increaseSize();
    }
}

// Search for a key in the hash table
int search(int key)
{
    int HI = key % hashSize;
    int initialHI = HI;

    // This condition shows that the key isn't present
    while (HT[HI] != -1)
    {
        // If key is found, return index
        if (HT[HI] == key)
        {
            return HI;
        }
        // Move to the next index
        HI = (HI + 1) % hashSize;

        // If we loop back to the start, we've checked the table fully
        if (HI == initialHI)
        {
            break;
        }
    }
    // Key not found
    return -1;
}

// Printing the hash table
void printArr()
{
    for (int i = 0; i < hashSize; i++)
    {
        cout << i << ": " << HT[i] << endl;
    }
}

int main()
{
    // Initialize the hash table with -1 to mark empty slots
    initializeArr(HT, hashSize);

    // Insert keys into the hash table
    insert(29);
    insert(31);
    insert(30);
    insert(34);
    insert(35);
    insert(37);

    // Print the hash table
    printArr();

    return 0;
}
