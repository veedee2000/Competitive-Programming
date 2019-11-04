class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int ans = 0,mmax = prices[1],mmin = prices[0];
        for(int i = 1;i < prices.size();i++){
            mmin = min(mmin, prices[i - 1]);
            ans = max(ans, prices[i] - mmin);
        }
        return ans;
    }
};
