//tc-O(n2) in all
//sc- O(1)

//comparative, in-place, stable

#include<bits/stdc++.h>
using namespace std;

void selection(vector<int> &arr){
    int n= arr.size();
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
    if(arr[j]<arr[i]){
        int t=arr[j];
        arr[j]=arr[i];
        arr[i]=t;
    }
}
}
}
int main(){
    vector<int> arr={9,3,5,7,2,9};
    selection(arr);
    for(auto it:arr)
    cout<<it;
}