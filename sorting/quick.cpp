//tc- o(nlogn), o(1)

//comparative, in-place, not stable

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int st, int ed){
    int p=arr[ed];
    int i=st-1;
    for(int j=st;j<ed;j++){
        if(arr[j]<=p){
            i++; swap(arr[i], arr[j]);
        }
    }
    cout<<p<<arr[ed];
    swap(arr[i+1],arr[ed]);
    return i+1;

}
void quick(vector<int> &arr,int st, int ed){
    if(st<ed){
int part= partition(arr, st, ed);
quick(arr, st,part-1);
quick(arr,part+1,ed);
    }
}
int main(){
    vector<int> arr={9,3,5,7,2,9};int n=6;
    quick(arr,0,5);

    for(auto it:arr)
    cout<<it;
}