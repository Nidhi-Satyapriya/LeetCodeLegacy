 #include<bits/stdc++.h>
 using namespace std;

 class Solution{
 
 public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, int par, vector<vector<int>>& adj,vector<int> &vis)
    {
        vis[node]=1;
       for (auto n : adj[node]) {
        if (!vis[n]) {
            if (dfs(n, node, adj, vis)) {
                return true;
            }
        } 
        else if (n != par) {
            return true;
        }
    }
    return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        
        vector<int> vis(adj.size(), 0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i])  
            {
                if (dfs(i, -1, adj, vis)==true) return true;
                
            }}
        return false;   }
};

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Initialize adjacency list
    vector<vector<int>> adj(nodes);

    cout << "Enter the edges (u v):" <<"\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution ob; 
    if (ob.isCycle(adj)) {
        cout << "The graph contains a cycle." << "\n";
    } else {
        cout << "The graph does not contain a cycle." << "\n";
    }

    return 0;
}