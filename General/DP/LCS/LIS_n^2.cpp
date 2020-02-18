class Solution {
public:
    vector<int>dp,nums;
    int lengthOfLIS(vector<int>& nums) {
        this -> nums = nums;
        dp.resize(nums.size(),-1);
        int ans = 0;
        for(int i = nums.size() - 1;i >= 0;i--){
            ans = max(ans,f(i));
        }
        return ans;
    }
    
    int f(int i){
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j = i - 1;j >= 0;j--){
            if(nums[j] < nums[i]) ans = max(ans,f(j));
        }
        return dp[i] = ans + 1;
    }
    
};

// Total Number of Operations performed = k1 * n ^ 2 + k2 * n ^ 2.
// Complexity = O (n ^ 2).
