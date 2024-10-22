#include <iostream>
using namespace std;

const int n = 5; // Number of vertices
bool visited[n];
int IDArr[n];

// Function to initialize the adjacency matrix
void initializeMatrix(int adjMatrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0; // Set all edges to 0 (no edge)
        }
    }
}

// Function to add a directed edge from u to v
void addEdge(int adjMatrix[n][n], int u, int v)
{
    // Check if u and v are within valid range
    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        cout << "Invalid vertices: " << u << ", " << v << endl;
        return;
    }

    // Set the edge from u to v
    adjMatrix[u][v] = 1; // 1 indicates the presence of an edge
}

void calculateOutDegree(int adjMatrix[n][n])
{
    int outdegree = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] != 0)
            {
                outdegree++;
            }
        }
        cout << "vertex " << i << " has an out-degree: " << outdegree << endl;
        outdegree = 0;
    }
}

void calculateInDegree(int adjMatrix[n][n])
{
    int indegree = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[j][i] != 0)
            {
                indegree++;
            }
        }
        IDArr[i] = indegree;
        indegree = 0;
    }
}

// Function to print the adjacency matrix
void printMatrix(int adjMatrix[n][n])
{
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printIndegree(){
    cout << "Printing indegree: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << IDArr[i] << endl;
    }
}

// Function to find a vertex with indegree zero that hasn't been visited
int findIDZeroVertex()
{
    for (int i = 0; i < n; i++)
    {
        if (IDArr[i] == 0 && !visited[i])
        {
            return i;
        }
    }
    return -1;
}

// Function to perform topological sorting
void topSort(int adjMatrix[n][n])
{
    int v = 0;

    for (int i = 0; i < n; i++)
    {
        v = findIDZeroVertex();
        if (v == -1)
        {
            cout << "Graph has a cycle" << endl;
            return;
        }
        cout << "vertex: " << v << endl;
        visited[v] = true;

        // Decrease indegree of vertices that have an edge from the current vertex
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[v][j] == 1)
            {
                IDArr[j]--;
            }
        }
    }
}

int main()
{
    // Initialize adjacency matrix
    int adjMatrix[n][n];
    initializeMatrix(adjMatrix);

    // Adding directed edges to the graph
    addEdge(adjMatrix, 1, 0);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    // Initialize visited array
    fill(visited, visited + n, false);

    // Calculate indegrees
    calculateInDegree(adjMatrix);

    // Perform topological sort
    topSort(adjMatrix);

    return 0;
}


// Array of linked lists to represent the adjacency list of the directed graph
// list<int> linkedListArray[n];

// void addEdge(int u, int v) {
//     // Check if u and v are within valid range
//     if (u < 0 || u >= n || v < 0 || v >= n) {
//         cout << "Invalid vertices: " << u << ", " << v << endl;
//         return;
//     }

//     // Add an edge from u to v (directed graph)
//     linkedListArray[u].push_back(v);
// }

// void printGraph() {
//     for (int i = 0; i < n; i++) {
//         cout << "Adjacency list of vertex " << i << ": ";
//         for (auto v : linkedListArray[i]) {
//             cout << v << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     // Adding directed edges to the graph
//     addEdge(0, 1);
//     addEdge(0, 4);
//     addEdge(1, 2);
//     addEdge(1, 3);
//     addEdge(2, 3);
//     addEdge(3, 4);

//     // Testing with invalid vertices
//     addEdge(5, 2);  // Invalid, since vertex 5 doesn't exist
//     addEdge(-1, 0); // Invalid, since vertex -1 doesn't exist

//     // Print the adjacency list representation of the graph
//     printGraph();

//     return 0;
// }
