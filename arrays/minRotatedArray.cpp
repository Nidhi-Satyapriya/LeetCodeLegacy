#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, ed = nums.size() - 1;

        while (st < ed) {
            int mid = st + (ed - st) / 2;

            if (nums[st] <= nums[mid]) {
                st = mid + 1;
            } else {
                ed = mid;
            }
        }

        return nums[st];
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    cout << sol.findMin(nums) << endl;
    return 0;
}