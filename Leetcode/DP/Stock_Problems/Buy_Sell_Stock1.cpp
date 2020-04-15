class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int minVal = prices[0],ans = 0;
        for(auto x:prices){
            ans = max(ans,x - minVal);
            minVal = min(minVal,x);
        }
        return ans;
    }
};
