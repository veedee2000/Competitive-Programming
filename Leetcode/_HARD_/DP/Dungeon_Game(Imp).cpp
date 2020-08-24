class Solution {
    
    vector<vector<int>>dp;
    int m, n;
    
    int f(int i, int j, vector<vector<int>>& dungeon){
        if(i == m or j == n) return INT_MAX;
        if(i == m - 1 and j == n - 1) return max(1 - dungeon[i][j], 1);
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = min(f(i + 1, j, dungeon), f(i,j + 1, dungeon));
        return dp[i][j] = max(dp[i][j] - dungeon[i][j], 1);
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size(), n = dungeon[0].size();
        dp.resize(m, vector<int>(n, -1));
        return f(0, 0, dungeon);
    }
};
