class Solution {
public:
    int printlongestCommonSubsequence(string a, string b) {
            int  n=a.size(), m=b.size();
            vector<vector<int>>dp(n+1, vector<int>(m+1,0));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
          return dp[n][m];
          // Backtrack to find the LCS string
        int i = n, j = m;
        string st = "";
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                st += a[i - 1];
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }

        reverse(st.begin(), st.end());
        return st;
    }
};