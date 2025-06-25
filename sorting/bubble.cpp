//tc-O(n2) in all
//sc- O(1)

//comparative, in-place, stable

#include<bits/stdc++.h>
using namespace std;

void bubble(vector<int> &arr){
    int n= arr.size();
for(int i=0;i<n;i++){
for(int j=0;j<n-i-1;j++){
    if(arr[j]<arr[j+1]){
        int t=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=t;
    }
}
}
}
int main(){
    vector<int> arr={9,3,5,7,2,9};
    bubble(arr);
    for(auto it:arr)
    cout<<it;
}