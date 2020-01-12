class Solution {
public:
    vector<int>dp;
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);
        return f(target,nums);
    }
    
    int f(int val,vector<int>& nums){
        if(val == 0) return 1;
        if(val < 0) return 0;
        if(dp[val] != -1) return dp[val];
        int ans = 0;
        for(auto x:nums) ans += f(val - x,nums);
        return dp[val] = ans;
    }
    
};
