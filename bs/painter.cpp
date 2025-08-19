bool isPossible(vector<int> &nums, int k, int mid) {
    int painters=1;
    int sum=0;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum > mid) { sum=nums[i]; painters++;}
        if(painters>k) return false;
    }
    return true;
}


int painter(vector<int> &nums, int k){
    int maxis= *max_element(nums.begin(), nums.end());
    int sum=accumulate(nums.begin(), nums.end(), 0);
    int low=maxis;
    int high=sum;
    int ans=0;
    while(low<high){
        int mid=low+(high-low)/2;
        if(isPossible(nums,k, mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
 }
 return ans;