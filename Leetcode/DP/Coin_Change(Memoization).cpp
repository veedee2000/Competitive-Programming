class Solution {
public:
    vector<int>dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1,-1);
        int ans = f(amount,coins);
        return ans == INT_MAX ? -1 : ans;
    }
    
    int f(int amount,vector<int>& coins){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;
        for(auto x:coins){
            ans = min(ans,f(amount - x,coins));
        }
        return dp[amount] = (ans == INT_MAX ? INT_MAX : ans + 1);
    }
};
