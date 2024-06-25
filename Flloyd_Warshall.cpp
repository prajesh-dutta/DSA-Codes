#include <iostream>
#include <vector>
#include <climits>

using namespace std;


void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}


void floydWarshall(const vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph; 

    
    for (int k = 0; k < V; k++) {
    
        for (int i = 0; i < V; i++) {
           
            for (int j = 0; j < V; j++) {
                
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

  
    printSolution(dist, V);
}

int main() {

    int V = 4;

 
    vector<vector<int>> graph = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    
    floydWarshall(graph, V);

    return 0;
}
