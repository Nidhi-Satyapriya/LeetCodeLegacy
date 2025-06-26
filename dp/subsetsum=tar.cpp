#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//memoization
    bool subsetSumHelper(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base Cases
        if (target == 0) return true;           // Subset sum 0 is always possible
        if (i == 0) return arr[0] == target;    // Only one element to pick from

        // If already computed
        if (dp[i][target] != -1) 
            return dp[i][target];

        // Exclude current element
        bool notPick = subsetSumHelper(i - 1, target, arr, dp);

        // Include current element if it's not greater than target
        bool pick = false;
        if (arr[i] <= target)
            pick = subsetSumHelper(i - 1, target - arr[i], arr, dp);

        return dp[i][target] = pick || notPick;
    }

    bool isSubsetSum(vector<int>arr, int target){
        int n= arr.size();
       vector<vector<bool>>dp(n+1, vector<bool>(target+1, false));
       for(int i=0;i<=n;i++)
       dp[i][0]=true;
       for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
           if(j>=arr[i-1]) dp[i][j]= dp[i-1][j-arr[i-1]];
           dp[i][j]=dp[i][j] || dp[i-1][j];
        }
       }
       return dp[n][target];
    }
    
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return subsetSumHelper(n - 1, target, arr, dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;

    if (sol.isSubsetSum(arr, target))
        cout << "Subset with given sum exists." << endl;
    else
        cout << "No subset with given sum exists." << endl;

    return 0;
}
