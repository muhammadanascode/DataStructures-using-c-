#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

const int n = 5; // Number of vertices
bool visited[n];
int distances[n];

// Function to initialize the adjacency matrix
void initializeMatrix(int adjMatrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = INT_MAX; // Set all edges to INT_MAX (no edge)
        }
    }
}

// Initialize distances array
void initializedistances()
{
    for (int i = 0; i < n; i++)
    {
        distances[i] = INT_MAX;
    }
}

// Function to add a directed edge from u to v with a weight
void addEdge(int adjMatrix[n][n], int u, int v, int weight)
{
    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        cout << "Invalid vertices: " << u << ", " << v << endl;
        return;
    }

    if (weight < 0)
    {
        cout << "Negative weights are invalid" << endl;
        return;
    }

    adjMatrix[u][v] = weight; // Set the weight for the edge from u to v
}

// Function to find the vertex with the smallest distances that hasn't been visited
int smallestdistancesVertex()
{
    int idx = -1;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (distances[i] < min && !visited[i])
        {
            min = distances[i];
            idx = i;
        }
    }
    return idx;
}

// Dijkstra's algorithm implementation
void Dijkstra(int adjMatrix[n][n], int source)
{
    distances[source] = 0;

    while (true)
    {
        int v = smallestdistancesVertex();
        if (v == -1) // If no vertex is found, break the loop
        {
            break;
        }
        visited[v] = true;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && adjMatrix[v][i] != INT_MAX) // Check if there's an edge
            {
                int cost = distances[v] + adjMatrix[v][i];
                if (cost < distances[i])
                {
                    distances[i] = cost;
                }
            }
        }
    }
}

// Function to print the shortest distancess from the source vertex
void printdistancess(int source)
{
    cout << "Shortest distancess from vertex " << source << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        if (distances[i] == INT_MAX)
        {
            cout << "Vertex " << i << ": Unreachable" << endl;
        }
        else
        {
            cout << "Vertex " << i << ": " << distances[i] << endl;
        }
    }
}

int main()
{
    // Initialize adjacency matrix
    int adjMatrix[n][n];
    initializeMatrix(adjMatrix);
    initializedistances();

    // Adding directed edges to the graph with weights
    addEdge(adjMatrix, 0, 1, 4);
    addEdge(adjMatrix, 0, 4, 3);
    addEdge(adjMatrix, 1, 2, 3);
    addEdge(adjMatrix, 1, 3, 2);
    addEdge(adjMatrix, 2, 3, 5);
    addEdge(adjMatrix, 3, 4, 7);

    // Initialize visited array
    fill(visited, visited + n, false);

    // Perform Dijkstra's algorithm starting from vertex 0
    Dijkstra(adjMatrix, 0);

    // Print the shortest distancess from the source vertex
    printdistancess(0);

    return 0;
}
