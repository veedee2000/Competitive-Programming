class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(),maxDiff = INT_MIN;
        if(!n) return 0;
        vector<int>dp(n);
        for(int i = 0;i < n;i++){
            if(i < 2) maxDiff = max(maxDiff,-prices[i]);
            if(i == 0) dp[0] = 0;
            else if(i == 1) dp[1] = max(prices[1] - prices[0] - fee,0);
            else{
                dp[i] = max(dp[i - 1],maxDiff + prices[i] - fee);
                maxDiff = max(maxDiff,dp[i - 1] - prices[i]);
            }
        }
        return dp[n - 1];
    }
};
