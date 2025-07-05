#include<bits/stdc++.h>
using namespace std;

string func(string a, string b){
    int m=a.size(), n=b.size();
     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i=m, j=n;string s="";
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                s+=a[i-1];i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                s+=a[i-1];i--;
            }
            else if(dp[i-1][j]<=dp[i][j-1]){
                s+=b[j-1];j--;
            }
        }
        while(i-->0) s+=a[i-1];
        while(j-->0)s+=b[j-1];
        reverse(s.begin(), s.end());
       return s;
        
}
int main(){
    string a="aaaaaabb", b="aaaabc";
    cout<<func(a,b);
    return 0;
}