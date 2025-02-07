#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) return 0; 
        vector<int>steps(100000, INT_MAX);
        steps[start]=0;
        queue<pair<int, int>> pq;  pq.push({start,0});
        while(!pq.empty()){
            auto it=pq.front();
            int no=it.first;
            int stp= it.second;
            pq.pop();
            
            for(auto r:arr){
                int newn=(r*no)% 100000;
                 if(newn==end) return stp+1;  
                if(steps[newn]> stp+1){
                 
                    steps[newn]=stp+1; pq.push({newn, stp+1});
                }
            }
        }
        return -1;
        
    }
};
int main(){
    vector<int> arr = {2, 3, 5};  // Example multipliers
    int start = 3, end = 30;
    Solution ob;
    cout << ob.minimumMultiplications(arr, start, end) << endl;
    return 0;
}

