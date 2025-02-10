#include <bits/stdc++.h>
using namespace std;

class PrimMST {
public:
    int findMST(int V, vector<vector<pair<int, int>>>& adj) {
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
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                if (!vis[adjNode]) {
                    pq.push({edw, adjNode});
                }
            }
        }
        return sum;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    PrimMST obj;
    cout << "Minimum Spanning Tree cost: " << obj.findMST(V, adj) << endl;
    
    return 0;
}
