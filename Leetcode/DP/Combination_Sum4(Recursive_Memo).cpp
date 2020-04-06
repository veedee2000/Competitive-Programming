class Solution {
public:
    vector<int>dp,nums;
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        this -> nums = nums;
        dp.resize(target + 1,-1);
        return f(target);
    }
    
    int f(int n){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(auto x:nums){
            if(n - x < 0) break;
            ans += f(n - x);
        }
        return dp[n] = ans;
    }
};
