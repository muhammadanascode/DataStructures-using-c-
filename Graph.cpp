#include <iostream>
using namespace std;
#include <list>

// Implementation of an undirected graph using adjacency matrix

const int n = 4;
// int edges = 0;
// int adjMatrix[n][n]; // Static 2D array

// void initializeArr()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             adjMatrix[i][j] = 0; // Initialize all elements to 0
//         }
//     }
// }

// void addEdge(int u, int v)
// {
//     // Check for valid indices (0 to n-1)
//     if (u < 0 || u >= n || v < 0 || v >= n)
//     {
//         cout << "Invalid edge!" << endl;
//         return;
//     }

//     adjMatrix[u][v] = 1;
//     adjMatrix[v][u] = 1;

//     edges++;
// }

// void print()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << adjMatrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// void calculateOutDegree()
// {
//     int outdegree = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (adjMatrix[i][j] != 0)
//             {
//                 outdegree++;
//             }
//         }
//         cout << "vertex " << i << " has a out degree: " << outdegree << endl;
//         outdegree = 0;
//     }
// }

// void calculateInDegree()
// {
//     int indegree = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (adjMatrix[j][i] != 0)
//             {
//                 indegree++;
//             }
//         }
//         cout << "vertex " << i << " has a in degree: " << indegree << endl;
//         indegree = 0;
//     }
// }

// int main()
// {
//     initializeArr();

//     // Add edges (indices must be 0-based)
//     addEdge(0, 1); // Equivalent to addEdge(1, 2) in your original code
//     addEdge(2, 1); // Equivalent to addEdge(3, 2)
//     addEdge(3, 2); // Equivalent to addEdge(4, 3)
//     addEdge(0, 3); // Equivalent to addEdge(1, 4)
//     calculateOutDegree() ;
//     calculateInDegree();

//     print();

//     return 0;
// }

// Implementation of Graphs using adjency list

list<int> linkedListArray[n];

void addEdge(int u, int v)
{
    // Check if u and v are within valid range
    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        cout << "Invalid vertices: " << u << ", " << v << endl;
        return;
    }

    // Add an edge from u to v (undirected graph, so add both directions)
    linkedListArray[u].push_back(v);
    linkedListArray[v].push_back(u);
}

void printGraph()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Adjacency list of vertex " << i << ": ";
        for (auto v : linkedListArray[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

void calculateOutDegree()
{
    int outdegree = 0;
    for (int i = 0; i < n; i++)
    {
        outdegree = linkedListArray[i].size();
        cout << "vertex " << i << " has a out degree: " << outdegree << endl;
    }
}

// Function to calculate the in-degree of each vertex
void calculateInDegree() {
    for (int i = 0; i < n; i++) {
        int indegree = 0;
        for (int j = 0; j < n; j++) {
            // Check if vertex i appears in the adjacency list of vertex j
            for (auto v : linkedListArray[j]) {
                if (v == i) {
                    indegree++;
                }
            }
        }
        cout << "Vertex " << i << " has an in degree: " << indegree << endl;
    }
}

int main()
{
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 0);
    addEdge(1, 3);
    calculateOutDegree();
    calculateInDegree() ;
    printGraph();

    return 0;
}
