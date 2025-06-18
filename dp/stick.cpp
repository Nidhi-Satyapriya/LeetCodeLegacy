#include<bits/stdc++.h>
using namespace std;

//recursion
int minimumCost( vector<int> &cuts, int s, int e){
if(s>e) return 0;
int mini=1e9;
for(int i=s;i<=e;i++)
mini=min(mini, cuts[e+1]-cuts[s-1]+ minimumCost(cuts,s,i-1)+ minimumCost(cuts,i+1, e));
return mini;
}

// memoize
int minimumCostMemo(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for (int k = i; k <= j; ++k) {
        int cost = cuts[j + 1] - cuts[i - 1] + 
                   minimumCostMemo(cuts, i, k - 1, dp) + 
                   minimumCostMemo(cuts, k + 1, j, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

//tabulate
int minimumCostTab(vector<int>& cuts, int n) {
    int c = cuts.size() - 2;
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int len = 1; len <= c; ++len) {
        for (int i = 1; i <= c - len + 1; ++i) {
            int j = i + len - 1;
            int mini = 1e9;
            for (int k = i; k <= j; ++k) {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n=7;
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    cout << "The minimum cost incurred is: " << minimumCost(cuts, 1, c-1) << endl;

    return 0;
}