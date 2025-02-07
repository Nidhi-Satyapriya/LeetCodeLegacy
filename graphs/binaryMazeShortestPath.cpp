

#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    int n = grid.size(), m = grid[0].size();

    // Edge cases: If start or destination is blocked
    if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
        return -1;

    // If source and destination are the same
    if (source == destination) return 0;

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[source.first][source.second] = 0;

    queue<pair<int, int>> q; // Simple BFS queue
    q.push({source.first, source.second});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int x = 0; x < 4; x++) {
            int nr = r + dr[x];
            int nc = c + dc[x];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && dist[r][c] + 1 < dist[nr][nc]) {
                dist[nr][nc] = dist[r][c] + 1;
                
                if (nr == destination.first && nc == destination.second)
                    return dist[nr][nc]; // Found shortest path
                
                q.push({nr, nc});
            }
        }
    }

    return -1;  // No path found
}
int main() {
    vector<vector<int>> grid = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 0, 1, 1, 1}
    };

    pair<int, int> source = {0, 0};        
    pair<int, int> destination = {4, 4};   

    int result = shortestPath(grid, source, destination);

    if (result != -1)
        cout << "Shortest Path Length: " << result << endl;
    else
        cout << "No valid path found!" << endl;

    return 0;
}