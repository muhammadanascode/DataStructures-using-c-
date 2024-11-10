#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

const int INF = INT_MAX; // Representing infinity

// Function to implement the Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();
    // Create a distance matrix initialized with the input graph's adjacency matrix
    vector<vector<int>> distances = graph;

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if there's a shorter path through vertex k
                if (distances[i][k] != INF && distances[k][j] != INF &&
                    distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    // Print the shortest distances matrix
    cout << "All-Pairs Shortest Path Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distances[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << distances[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // Define the graph using an adjacency matrix
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    // Execute the Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}
