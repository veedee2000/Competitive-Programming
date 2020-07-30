class Solution {
    
    vector<vector<vector<int>>>dp;
    int m, n;
    
    int f(int r1, int c1, int c2, vector<vector<int>>& grid){
        
        int r2 = r1 + c1 - c2;
        
        if(r1 == m or r2 == m or c1 == n or c2 == n) return -2 * (m + n);
        
        if(grid[r1][c1] == -1 or grid[r2][c2] == -1) return -2 * (m + n);
        
        if(r1 + c1 == m + n - 2) return grid[m - 1][n - 1];
        
        if(dp[r1][c1][c2] != INT_MIN) return dp[r1][c1][c2];
        
        int val;
        
        if(r1 == r2 and c1 == c2) val = grid[r1][c1];
        else val = grid[r1][c1] + grid[r2][c2];
        
        return dp[r1][c1][c2] = val + max({f(r1 + 1, c1, c2, grid), f(r1, c1 + 1, c2, grid), f(r1 + 1, c1, c2 + 1, grid), f(r1, c1 + 1, c2 + 1, grid)});
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(f(0, 0, 0, grid), 0);
    }
};
