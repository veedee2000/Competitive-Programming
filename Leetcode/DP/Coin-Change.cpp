class Solution {
private:
    int dp[11000],i,b[11000],j;
public:
    Solution(){
        for(i=0;i<10000;i++) dp[i] = 100000000;
        for(i=0;i<10000;i++) b[i] = 0;
    }
    int coinChange(vector<int>& coins, int amount) {
        return (ans(coins,amount) >= 100000000) ? -1 : ans(coins,amount);
    }
    int ans(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return 100000000;
        if(b[amount] == 1) return dp[amount];
        b[amount]=1;
        for(auto x:coins){
            dp[amount] = min(dp[amount],ans(coins,amount - x) + 1);
        }
        return dp[amount];
    }
};
