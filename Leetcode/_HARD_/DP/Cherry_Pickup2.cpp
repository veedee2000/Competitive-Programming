class Solution {
    
    vector<vector<vector<int>>>dp;
    int m, n;
    vector<int>d = {-1, 0, 1};
    
    int f(int i, int j1, int j2, vector<vector<int>>& grid){
        if(i == m) return 0;
        if(j1 == -1 or j2 == n) return INT_MIN;
        if(j1 >= j2) return INT_MIN;
        if(dp[i][j1][j2] != INT_MAX) return dp[i][j1][j2];
        int ans = 0;
        for(int j11 = 0;j11 < 3;j11++){
            for(int j22 = 0;j22 < 3;j22++){
                ans = max(ans, f(i + 1, j1 + d[j11], j2 + d[j22], grid));
            }
        }
        return dp[i][j1][j2] = ans + grid[i][j1] + grid[i][j2];
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(n, INT_MAX)));
        return f(0, 0, n - 1, grid);
    }
};
