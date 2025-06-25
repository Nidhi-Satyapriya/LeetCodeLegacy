//tc- o(n2), o(1)

//comparative, in-place, stable

#include<bits/stdc++.h>
using namespace std;

void insertion(vector<int> &arr){
int n= arr.size();
for(int i=0;i<n;i++){
    int j=i-1;
while( j>=0 && arr[j]>arr[i]){
    arr[j+1]=arr[j]; j--;
    }
    arr[j+1]=arr[i];
}
}
int main(){
    vector<int> arr={9,3,5,7,2,9};
    insertion(arr);
    for(auto it:arr)
    cout<<it;
}