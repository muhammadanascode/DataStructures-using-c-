#include <iostream>
using namespace std;

const int n = 5;  // Number of vertices

// Function to initialize the adjacency matrix
void initializeMatrix(int adjMatrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0; // Set all edges to 0 (no edge)
        }
    }
}

// Function to add a directed edge from u to v
void addEdge(int adjMatrix[n][n], int u, int v) {
    // Check if u and v are within valid range
    if (u < 0 || u >= n || v < 0 || v >= n) {
        cout << "Invalid vertices: " << u << ", " << v << endl;
        return;
    }

    // Set the edge from u to v
    adjMatrix[u][v] = 1; // 1 indicates the presence of an edge
}

// Function to print the adjacency matrix
void printMatrix(int adjMatrix[n][n]) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Initialize adjacency matrix
    int adjMatrix[n][n];
    initializeMatrix(adjMatrix);

    // Adding directed edges to the graph
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    // Testing with invalid vertices
    addEdge(adjMatrix, 5, 2);  // Invalid, since vertex 5 doesn't exist
    addEdge(adjMatrix, -1, 0); // Invalid, since vertex -1 doesn't exist

    // Print the adjacency matrix representation of the graph
    printMatrix(adjMatrix);

    return 0;
}
