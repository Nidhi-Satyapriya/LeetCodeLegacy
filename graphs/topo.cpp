#include <bits/stdc++.h>
using namespace std;

class Topo {
public:
    void add(int u, int v, vector<vector<int>> &adj) {
        adj[u].push_back(v);
    }

    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }

    void topoSort(vector<vector<int>> &adj, vector<int> &ans) {
        int n = adj.size();
        vector<bool> visited(n, false);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }
};

int main() {
    int n, t;
    cin >> n >> t; // n = number of nodes, t = number of operations

    vector<vector<int>> adj(n); // initialize with n nodes
    vector<int> ans;
    Topo ob;

    while (t-- > 0) {
        int opt;
        cin >> opt;

        if (opt == 1) {
            int u, v;
            cin >> u >> v;
            ob.add(u, v, adj);
        } else if (opt == 2) {
            ans.clear(); // clear previous result
            ob.topoSort(adj, ans);
            for (auto it : ans) cout << it << " ";
            cout << endl;
        }
    }

    return 0;
}
