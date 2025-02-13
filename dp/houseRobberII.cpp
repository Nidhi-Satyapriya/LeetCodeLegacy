#include <bits/stdc++.h>
using namespace std;

int robHelper(vector<int>& arr, int i, vector<int>& dp) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    dp[i] = max(arr[i] + robHelper(arr, i - 2, dp), robHelper(arr, i - 1, dp));
    return dp[i];
}

int rob(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];

    vector<int> case1(arr.begin(), arr.end() - 1);
    vector<int> case2(arr.begin() + 1, arr.end());

    vector<int> dp1(n, -1), dp2(n, -1);
    
    return max(robHelper(case1, case1.size() - 1, dp1), robHelper(case2, case2.size() - 1, dp2));
}

int main() {
    vector<int> arr = {2, 3, 2};
    cout << rob(arr) << endl;
    return 0;
}
