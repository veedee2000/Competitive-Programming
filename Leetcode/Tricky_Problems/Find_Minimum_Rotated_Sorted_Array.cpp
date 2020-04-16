class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size() - 1,m;
        if(nums.size() == 1) return nums[0];
        if(nums[l] < nums[r]) return nums[0];
        while(l < r){
            m = l + (r - l) / 2;
            if(nums[m] > nums[m + 1]) return nums[m + 1];
            if(m > 0 and nums[m - 1] > nums[m]) return nums[m];
            if(m < nums.size() - 1 and nums[m] > nums[m + 1]) return nums[m + 1];
            if(nums[m] > nums[l] and nums[m] > nums[r]) l = m + 1;
            else if(nums[m] < nums[l] and nums[m] < nums[r]) r = m - 1;
        }
        return nums[0];
    }
};
