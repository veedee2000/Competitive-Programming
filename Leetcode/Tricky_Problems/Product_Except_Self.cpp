class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),left = nums[0];
        vector<int>ans = nums;
        for(int i = n - 2;i > 0;i--) nums[i] = nums[i + 1] * nums[i];
        ans[0] = nums[1];
        for(int i = 1;i < n - 1;i++){
            int temp = left * ans[i];
            ans[i] = left * nums[i + 1];
            left = temp;
        }
        ans[n - 1] = left;
        return ans;
    }
};
