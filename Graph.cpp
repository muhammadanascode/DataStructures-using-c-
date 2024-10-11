#include <iostream>
using namespace std;

// Implementation of an undirected graph using adjacency matrix

const int n = 4;
int edges = 0;
int adjMatrix[n][n];  // Static 2D array

void initializeArr()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;  // Initialize all elements to 0
        }
    }
}

void addEdge(int u, int v)
{
    // Check for valid indices (0 to n-1)
    if (u < 0 || u >= n || v < 0 || v >= n) {
        cout << "Invalid edge!" << endl;
        return;
    }
    
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;

    edges++;
}

void print()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    initializeArr();
    
    // Add edges (indices must be 0-based)
    addEdge(0, 1);  // Equivalent to addEdge(1, 2) in your original code
    addEdge(2, 1);  // Equivalent to addEdge(3, 2)
    addEdge(3, 2);  // Equivalent to addEdge(4, 3)
    addEdge(0, 3);  // Equivalent to addEdge(1, 4)
    
    print();
    
    return 0;
}
