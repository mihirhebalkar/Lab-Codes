#include <bits/stdc++.h>
using namespace std;


int spanningTree(int V, vector<vector<int>>& adjMatrix) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) continue;

        vis[node] = 1;
        sum += wt;

        for (int i = 0; i < V; ++i) {
            if (adjMatrix[node][i] != 0 && !vis[i]) {
                pq.push({adjMatrix[node][i], i});
            }
        }
    }
    return sum;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    

      vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
    
    // Fill the adjacency matrix
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // For undirected graph
    }

    int sum = spanningTree(V, adjMatrix);
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}
