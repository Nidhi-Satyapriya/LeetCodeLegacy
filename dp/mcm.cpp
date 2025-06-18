#include<bits/stdc++.h>
using namespace std;


//recursion

// int matrixMultiplication(vector<int> &arr, int e, int s){
//     int mini=INT_MAX;
//     if(e==s) return 0;
// for(int k=s;k<e;k++){
//     mini=min(mini, arr[s-1]*arr[k]*arr[e]+ matrixMultiplication(arr,k,s)+ matrixMultiplication(arr, e, k+1));
// }
// return mini;
// }

//recurrence

// int matrixMultiplication(vector<int> &arr, int e, int s, vector<vector<int>> &dp){
//     int mini=INT_MAX;
//     if(e==s) return 0;
//     if(dp[s][e]!=-1) return dp[s][e];
// for(int k=s;k<e;k++){
//     mini=min (mini, arr[s-1]*arr[k]*arr[e]+ matrixMultiplication(arr,k,s,dp)+ matrixMultiplication(arr, e, k+1, dp));
// }
// return dp[s][e]= mini;
// }

//tabulation
int matrixMultiplication(vector<int> &arr, int n, vector<vector<int>> &dp ){
   for(int i=1;i<n;i++) dp[i][i]=0;

for (int len = 2; len < n; len++) {
    for (int i = 1; i < n - len + 1; i++) {
        int j = i + len - 1;
        dp[i][j] = INT_MAX;

        for (int k = i; k < j; k++) {
            int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
            dp[i][j] = min(dp[i][j], cost);
        }
    }
}

   return dp[1][n-1];
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout << "The minimum number of operations for matrix multiplication is " << matrixMultiplication(arr, n, dp) << endl;
    return 0;
}