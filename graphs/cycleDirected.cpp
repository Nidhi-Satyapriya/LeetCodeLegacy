#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build adjacency list and compute in-degrees
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If count != V, there is a cycle
        return count != V;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}  // This edge creates a cycle
    };

    Solution sol;
    if (sol.isCyclic(V, edges)) {
        cout << "Graph contains a cycle\n";
    } else {
        cout << "Graph does not contain a cycle\n";
    }

    return 0;
}
