#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortestDistance(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Replace -1 with a large number (1e9) to indicate no direct path
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if (i == j) matrix[i][j] = 0;
            }
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        // Convert back unreachable paths (1e9) to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

// **Main function to test Floyd-Warshall Algorithm**
int main() {
    vector<vector<int>> matrix = {
        {0, 3, -1, 7},
        {8, 0, 2, -1},
        {5, -1, 0, 1},
        {2, -1, -1, 0}
    };

    Solution sol;
    sol.shortestDistance(matrix);

    // Print the shortest distance matrix
    cout << "Shortest Distance Matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == -1)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
