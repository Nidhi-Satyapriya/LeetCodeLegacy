#include <bits/stdc++.h>
using namespace std;

class Topo {
public:
    void add(int u, int v, vector<vector<int>> &adj, vector<int> &inDegree) {
        adj[u].push_back(v);
        inDegree[v]++;
    }

    void topoSort(vector<vector<int>> &adj, vector<int> &inDegree, vector<int> &ans) {
        int n = adj.size();
        queue<int> q;

        // Push all nodes with in-degree 0
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int n, t;
    cin >> n >> t; // n = number of nodes, t = number of operations

    vector<vector<int>> adj(n);       // adjacency list
    vector<int> inDegree(n, 0);       // in-degree of each node
    vector<int> ans;                  // result

    Topo ob;

    while (t-- > 0) {
        int opt;
        cin >> opt;

        if (opt == 1) {
            int u, v;
            cin >> u >> v;
            ob.add(u, v, adj, inDegree);
        } else if (opt == 2) {
            ans.clear();
            vector<int> tempInDegree = inDegree; // Make a copy to preserve original for future calls
            ob.topoSort(adj, tempInDegree, ans);

            if (ans.size() != n) {
                cout << "Cycle detected! Topological sort not possible.\n";
            } else {
                for (int node : ans) {
                    cout << node << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
