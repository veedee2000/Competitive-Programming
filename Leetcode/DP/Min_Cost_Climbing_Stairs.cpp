class Solution {
public:
    vector<int>dp;
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(), -1);
        return min(f(0,cost),f(1,cost));
    }
    
    int f(int i, vector<int>& cost){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(f(i + 1, cost), f(i + 2, cost));
    }
};
