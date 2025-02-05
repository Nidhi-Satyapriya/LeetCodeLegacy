//https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>& edges) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    vector<int> par(n + 1, -1);
    vector<vector<pair<int, int>>> adj(n + 1);  // Resize properly
    int fin_dist = -1;

    // Build adjacency list
    for (auto f : edges) {
        adj[f[0]].push_back({f[1], f[2]});
        adj[f[1]].push_back({f[0], f[2]});
    }

    // Initialize
    for (int i = 1; i <= n; i++) par[i] = i;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[node]) continue; // Skip outdated entries

        if (node == n) fin_dist = d;

        for (auto nbr : adj[node]) {
            int nextNode = nbr.first;
            int weight = nbr.second;

            if (dist[node] + weight < dist[nextNode]) {
                dist[nextNode] = dist[node] + weight;
                pq.push({dist[nextNode], nextNode});
                par[nextNode] = node;
            }
        }
    }

    if (dist[n] == INT_MAX) return {-1};  // No path found

    // Retrieve path
    vector<int> path;
    int node = n;
    while (par[node] != node) {
        path.push_back(node);
        node = par[node];
    }
    path.push_back(1);
    path.push_back(fin_dist);
    reverse(path.begin(), path.end());

    return path;
}
