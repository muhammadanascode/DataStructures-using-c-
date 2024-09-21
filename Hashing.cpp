#include <iostream>
#include <string>
using namespace std;

// hash size and hash table
int hashSize = 7;
int *HT = new int[hashSize];

// Number of elements in hash table
int n = 0;

// function to initialize array with zeros
void initializeArr(int *&arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
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

// Increasing the size of the hash table and copying the elements
void increaseSize()
{
    // new hash size and hash table
    int newHashSize = findNextPrime();
    int *newHT = new int[newHashSize];

    // initialize new hash table with zeros
    initializeArr(newHT, newHashSize);

    // copying the indexes of old hash table into new hash table
    for (int i = 0; i < hashSize; i++)
    {
        if (HT[i] != 0)
        {
            int key = HT[i];
            int newHI = key % newHashSize;

            if (newHT[newHI] == 0)
            {
                newHT[newHI] = key;
            }
            else
            {
                // moving ahead of hash index until we found available index
                while (newHT[newHI] != 0)
                {
                    newHI = (newHI + 1) % newHashSize;
                }
                newHT[newHI] = key;
            }
        }
    }

    delete[] HT; // free the old hash table memory
    HT = newHT;
    hashSize = newHashSize;
}

// Checking if the key already exists in the hash table
bool contains(int key)
{
    int HI = key % hashSize;
    while (HT[HI] != 0)
    {
        if (HT[HI] == key)
            return true;
        HI = (HI + 1) % hashSize;
    }
    return false;
}

void insert(int key)
{
    // Check if the key already exists in the hash table
    if (contains(key))
    {
        cout << "Key " << key << " is already present in the hash table." << endl;
        return;
    }

    // calculating hash index
    int HI = key % hashSize;

    // if hash index is available
    if (HT[HI] == 0)
    {
        HT[HI] = key;
        n++;
    }
    else
    {
        // moving ahead of hash index until we found available index
        while (HT[HI] != 0)
        {
            HI = (HI + 1) % hashSize;
        }
        HT[HI] = key;
        n++;
    }

    // Update the global load factor after each insertion
    double loadFactor = (double)n / hashSize;

    // If load factor exceeds 0.5, increase the size of the hash table
    if (loadFactor > 0.5)
    {
        increaseSize();
    }
}

int search(int key)
{
    int HI = key % hashSize;
    int initialHI = HI;

    // This condition shows that key isn't present
    while (HT[HI] != -1)
    {
        // if key founded return index
        if (HT[HI] == key)
        {
            return HI;
        }
        // move to next index
        HI = (HI + 1) % hashSize;

        // If we loop back to the start means we checked the table fully and the key isn't present
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
        cout << HT[i] << endl;
    }
}

int main()
{
    // initialize array with zeros
    initializeArr(HT, hashSize);

    insert(29);
    insert(31);
    insert(30);
    insert(34);
    insert(35);
    insert(37);

    printArr();

    return 0;
}
