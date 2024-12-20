// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). 
// Find the number of islands.

// gfg link- https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void dfs(int i, int j,int m, int n, vector<vector<char>> &a, vector<vector<int>> &vis){
        vis[i][j]=1;
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};
        for(int p=0;p<8;p++){
            int ri= i+dr[p]; int ci= j+dc[p];
            if(ri>=0 && ri<n && ci>=0 && ci<m && a[ri][ci]=='1' && vis[ri][ci]==0)
            dfs(ri,ci, m,n,a,vis);   // traverse all connecting 1s
        }
            }
    int numIslands(vector<vector<char>>& a) {
        int n= a.size(); int m= a[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0) );
       int ct=0;
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1' && !vis[i][j]) {  //found 1; now traverse all connecting 1's (since these represent a collective island)
                ct++;
                dfs(i, j, m, n, a, vis);
            }
        }
    }
           
       return ct;
    }};

int main(){
int tc; cin>>tc;
while(tc--){
 int n,m; cin>>n>>m;
 vector<vector<char>> a(n, vector<char>(m,'#'));
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       cin>> a[i][j];
    }
 }
 Solution obj;
 int ans= obj.numIslands(a);
 cout<<ans<<"\n";
 cout<<"~"<<"\n";
 
}
return 0;
}