class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0,r = nums.size() - 1,m,ans;
        if(nums[nums.size() - 1] < target) return nums.size();
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) l = m + 1;
            else ans = m,r = m - 1;
        }
        return ans;
    }
};
