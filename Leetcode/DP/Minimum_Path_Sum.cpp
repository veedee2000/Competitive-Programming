const int INF = 1000000;
class Solution {
public:
    vector<vector<int>>dp;
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() < 1) return 0;
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
        return f(0,0,grid);
    }
    
    int f(int i,int j,vector<vector<int>>& grid){
        if(i > grid.size() - 1 or j > grid[0].size() - 1) return INF;
        if(i == grid.size() - 1 and j == grid[0].size() - 1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(f(i + 1,j,grid),f(i,j + 1,grid));
    }
};
