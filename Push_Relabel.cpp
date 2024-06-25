#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


void initializePreflow(vector<vector<int>>& capacity, vector<int>& height, vector<int>& excess, int s) {
    int V = capacity.size();
    for (int i = 0; i < V; ++i) {
        height[i] = 0;
        excess[i] = 0;
    }
    height[s] = V;
    for (int i = 0; i < V; ++i) {
        if (capacity[s][i] > 0) {
            excess[i] = capacity[s][i];
            excess[s] -= capacity[s][i];
            capacity[i][s] = capacity[s][i];
            capacity[s][i] = 0;
        }
    }
}


void push(vector<vector<int>>& capacity, vector<vector<int>>& flow, vector<int>& excess, int u, int v) {
    int send = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += send;
    flow[v][u] -= send;
    excess[u] -= send;
    excess[v] += send;
}


void relabel(vector<vector<int>>& capacity, vector<vector<int>>& flow, vector<int>& height, int u) {
    int V = capacity.size();
    int min_height = INT_MAX;
    for (int v = 0; v < V; ++v) {
        if (capacity[u][v] - flow[u][v] > 0) {
            min_height = min(min_height, height[v]);
            height[u] = min_height + 1;
        }
    }
}


int pushRelabel(vector<vector<int>>& capacity, int s, int t) {
    int V = capacity.size();
    vector<vector<int>> flow(V, vector<int>(V, 0));
    vector<int> excess(V);
    vector<int> height(V);
    initializePreflow(capacity, height, excess, s);

    queue<int> activeVertices;
    for (int i = 0; i < V; ++i) {
        if (i != s && i != t) {
            activeVertices.push(i);
        }
    }

    while (!activeVertices.empty()) {
        int u = activeVertices.front();
        activeVertices.pop();
        int old_height = height[u];
        while (excess[u] > 0) {
            bool pushed = false;
            for (int v = 0; v < V && excess[u] > 0; ++v) {
                if (capacity[u][v] - flow[u][v] > 0 && height[u] == height[v] + 1) {
                    push(capacity, flow, excess, u, v);
                    if (!pushed) {
                        activeVertices.push(u);
                        pushed = true;
                    }
                }
            }
            if (!pushed) {
                relabel(capacity, flow, height, u);
                activeVertices.push(u);
            }
        }
        if (height[u] > old_height) {
            activeVertices.push(u);
        }
    }

    return excess[t];
}

int main() {
   
    int V = 6;
    vector<vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    cout << "The maximum possible flow is " << pushRelabel(capacity, 0, 5) << endl;

    return 0;
}

