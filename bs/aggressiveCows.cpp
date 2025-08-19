int check(vector<int>& nums, int k, int mid) {
    int pos=nums[0];
    int cows=1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]-pos >= mid) {
            cows++;
            pos=nums[i];
        }   
        if(cows>k) return false;
    }   
    return
        true;
}
int aggressiveCows(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int low=1, high=nums[nums.size()-1]-nums[0];
    int ans=0;
    while(low<=high) {
        int mid=low+(high-low)/2;
        if(check(nums, k, mid)) {
            ans=mid;
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    return ans;
    return 0;
}
