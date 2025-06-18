#include <bits/stdc++.h>
using namespace std;

vector<int> getLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1), prev(n, -1);
    
    int maxi = 1, ind = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            ind = i;
        }
    }

    // Reconstruct LIS
    vector<int> lis;
    while (ind != -1) {
        lis.push_back(arr[ind]);
        ind = prev[ind];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
