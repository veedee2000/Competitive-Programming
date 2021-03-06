class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() < 1) return 0;
        for(int i = 0;i < prices.size() - 1;i++){
            if(prices[i+1] > prices[i]) ans += prices[i+1] - prices[i];
        }
        return ans;
    }
};
