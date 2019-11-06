class Solution {
public:
    vector<vector<int>>dp;
    int count[3] = {1,7,30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(),vector<int>(365 + 30, INT_MAX));
        return f(0,0,days,costs);
    }
    
    int f(int i,int j,vector<int>& days, vector<int>& costs){
        if(i >= days.size()) return 0;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        for(int k = 0;k < 3;k++){
            if(days[i] < j) dp[i][j] = min(dp[i][j],f(i + 1,j,days,costs));
            
            else dp[i][j] = min(dp[i][j],costs[k] + f(i + 1,days[i] + count[k],days,costs));
        }
        return dp[i][j];
    }
};
