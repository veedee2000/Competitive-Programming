class Solution {
    
    vector<vector<vector<int>>>dp;
    
    int f(int i, int color, int target, int& m, int& n, vector<int>& houses, vector<vector<int>>& cost){
        
        if(target < 0) return INT_MAX;
        
        if(i == m) return target ? INT_MAX : 0;
        
        if(dp[i][color][target] != -1) return dp[i][color][target];
        
        if(houses[i]) return dp[i][color][target] = f(i + 1,houses[i],target - (color != houses[i]),m,n,houses,cost);
        
        int ans = INT_MAX;
        
        for(int c = 0;c < n;c++){
            int val = f(i + 1,c + 1,target - (color != c + 1),m,n,houses,cost);
            if(val == INT_MAX) continue;
            ans = min(ans,cost[i][c] + val);
        }
        
        return dp[i][color][target] = ans;
    }
    
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp.resize(m,vector<vector<int>>(n + 1,vector<int>(target + 1,-1)));
        int ans = f(0,0,target,m,n,houses,cost);
        return ans != INT_MAX ? ans : -1;
    }
};
