class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),1);
        int left = 1,right = 1;
        for(int i = 0,j = nums.size() - 1;i < nums.size() and j >= 0;i++,j--){
            ans[i] *= left;
            ans[j] *= right;
            left *= nums[i];
            right *= nums[j];
        }
        return ans;
    }
};
