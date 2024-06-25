#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int bfs(vector<vector<int>>& residualGraph, int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next = 0; next < residualGraph.size(); next++) {
            if (parent[next] == -1 && residualGraph[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, residualGraph[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}


int edmondsKarp(vector<vector<int>>& graph, int s, int t) {
    int flow = 0;
    vector<int> parent(graph.size());
    int new_flow;

    while (new_flow = bfs(graph, s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            graph[prev][cur] -= new_flow;
            graph[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
   
    int V = 6;
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    cout << "The maximum possible flow is " << edmondsKarp(graph, 0, 5) << endl;

    return 0;
}

