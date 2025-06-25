//tc- o(nlogn), o(n)

//comparative, place,  stable

#include<bits/stdc++.h>
using namespace std;

void sortm(vector<int>&arr, int st, int mid, int ed){
      vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= ed) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= ed) temp.push_back(arr[j++]);

    // Copy back to original array
    for (int k = st; k <= ed; k++) {
        arr[k] = temp[k - st];
    }
}
void merge(vector<int> &arr,int st, int ed){
    if(st<ed){
        int part= st+(ed-st)/2;
merge(arr, st,part);
merge(arr,part+1,ed);
sortm(arr,st,part, ed);
    }
}
int main(){
    vector<int> arr={9,3,5,7,2,9};int n=6;
    merge(arr,0,5);

    for(auto it:arr)
    cout<<it;
}