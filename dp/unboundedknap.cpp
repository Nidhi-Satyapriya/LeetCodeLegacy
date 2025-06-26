class Solution {
public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int w) {
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= w; j++) {
                if (j >= wt[i - 1])
                    dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][w];
    }
};
