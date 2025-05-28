#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& gp) {
        int m = gp.size();
        vector<int> col(m, 0);
        vector<int> vis(m, 0);

        for (int i = 0; i < m; i++) {
            if (!vis[i]) {
                queue<pair<int, int>> q;
                q.push({i, 1});
                col[i] = 1;
                vis[i] = 1;

                while (!q.empty()) {
                    auto tp = q.front(); q.pop();
                    for (auto ad : gp[tp.first]) {
                        if (!vis[ad]) {
                            vis[ad] = 1;
                            col[ad] = -tp.second;
                            q.push({ad, col[ad]});
                        } else {
                            if (col[ad] == col[tp.first]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    // Example graph represented as adjacency list
    // 0 - 1
    // |   |
    // 3 - 2
    vector<vector<int>> graph = {
        {1, 3}, // neighbors of node 0
        {0, 2}, // neighbors of node 1
        {1, 3}, // neighbors of node 2
        {0, 2}  // neighbors of node 3
    };

    Solution sol;
    if (sol.isBipartite(graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
