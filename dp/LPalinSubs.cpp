class Solution {
public:
    // Memoization table
    vector<vector<int>> dp;

    int rec(string &s, int i, int j) {
        // Base case
        if (i > j) return 0;
        if (i == j) return 1;

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            dp[i][j] = 2 + rec(s, i + 1, j - 1);
        } else {
            dp[i][j] = max(rec(s, i + 1, j), rec(s, i, j - 1));
        }

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return rec(s, 0, n - 1);
    }
};
// -------------------------------------------------------------------------------

//tabulation

   int longestPalindromeSubseq(string s) {
      //  s=" "+s;
        int n=s.size(); 
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
     //  return rec(s,0,n-1, dp);
        for(int i=0;i<n;i++){
           dp[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
                else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }