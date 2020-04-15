class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int minVal = prices[0],ans = 0;
        for(auto x:prices){
            if(x > minVal) ans += x - minVal;
            minVal = x;
        }
        return ans;
    }
};
