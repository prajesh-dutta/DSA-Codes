#include <iostream>
#include <vector>
#include <limits>

using namespace std;


struct Edge {
    int source, destination, weight;
};


void printSolution(const vector<int>& distance, int n) {
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < n; ++i)
        cout << i << "\t\t" << distance[i] << endl;
}


bool bellmanFord(const vector<Edge>& edges, int V, int E, int src, vector<int>& distance) {
    
    for (int i = 0; i < V; i++)
        distance[i] = numeric_limits<int>::max();
    distance[src] = 0;

    
    for (int i = 1; i <= V - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

   
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return false; 
        }
    }

    return true;
}

int main() {
    int V = 5; 
    int E = 8; 
    vector<Edge> edges(E);

   
    edges[0] = {0, 1, -1};
    edges[1] = {0, 2, 4};
    edges[2] = {1, 2, 3};
    edges[3] = {1, 3, 2};
    edges[4] = {1, 4, 2};
    edges[5] = {3, 2, 5};
    edges[6] = {3, 1, 1};
    edges[7] = {4, 3, -3};

    vector<int> distance(V);
    if (bellmanFord(edges, V, E, 0, distance)) {
        printSolution(distance, V);
    }

    return 0;
}

