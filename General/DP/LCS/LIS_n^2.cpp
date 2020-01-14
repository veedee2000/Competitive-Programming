class Solution {
public:
    vector<int>dp;
    int findNumberOfLIS(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return f(nums.size() - 1,nums);
    }
    
    int f(int i,vector<int>& nums){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j = 0;j < i;j++){
            if(nums[i] > nums[j]) ans = max(ans,f(j,nums));
        }
        return dp[i] = ans + 1;
    }
};
