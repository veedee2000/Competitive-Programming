class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, n = nums.size();
        for(i = n - 1;i >= 1;i--){
            if(nums[i - 1] < nums[i]) break;
        }
        reverse(nums.begin() + i, nums.end());
        if(i){
            int index = lower_bound(nums.begin() + i, nums.end(), nums[i - 1] + 1) - nums.begin();
            swap(nums[index], nums[i - 1]);
        }
    }
};
