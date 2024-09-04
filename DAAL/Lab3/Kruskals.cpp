#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the parent of a node
int findParent(int node, vector<int>& parent) {
    if (node != parent[node])
        parent[node] = findParent(parent[node], parent); // Path compression
    return parent[node];
}

// Function to union two subsets
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Function to find the sum of weights of the edges of the Minimum Spanning Tree
int spanningTree(int V, vector<vector<int>>& adjMatrix) {
    vector<pair<int, pair<int, int>>> edges;

    // Convert adjacency matrix to edge list
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (adjMatrix[i][j] != 0) {
                edges.push_back({adjMatrix[i][j], {i, j}});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    vector<int> parent(V);
    vector<int> rank(V, 0);

    // Initialize parent for each node
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    int mstWt = 0;

    // Process edges in ascending order of weights
    for (auto& edge : edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // If u and v are in different sets, include this edge in the MST
        if (findParent(u, parent) != findParent(v, parent)) {
            mstWt += wt;
            unionSets(u, v, parent, rank);
        }
    }

    return mstWt;
}

int main() {
    int V = 5;
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // Undirected graph
    }

    int mstWt = spanningTree(V, adjMatrix);
    cout << "The sum of all the edge weights: " << mstWt << endl;

    return 0;
}
