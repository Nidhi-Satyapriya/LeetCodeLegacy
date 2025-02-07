#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int>dis(V, 1e8);
    dis[src]=0;
    
    for(int i=0;i<V-1;i++){
        for(auto it: edges){
           int u=it[0], v= it[1], wt=it[2];
           if(dis[u]!=1e8 && dis[u]+wt<dis[v])
           dis[v]= dis[u]+wt;
        }
    }
    
    // Nth relaxation to check negative cycle
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
            return { -1};
        }
    }


    return dis;
}
int main(){
    int V = 5;  // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, -1}, 
        {0, 2, 4}, 
        {1, 2, 3}, 
        {1, 3, 2}, 
        {1, 4, 2}, 
        {3, 2, 5}, 
        {3, 1, 1}, 
        {4, 3, -3}
    };

    int S = 0;  // Source vertex

    vector<int> result = bellmanFord(V, edges, S);

    // Output the shortest distances
    if (result.size() == 1 && result[0] == -1) {
        cout << "Negative weight cycle detected!" << endl;
    } else {
        cout << "Shortest distances from source " << S << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (result[i] == INT_MAX)
                cout << "INF ";
            else
                cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}