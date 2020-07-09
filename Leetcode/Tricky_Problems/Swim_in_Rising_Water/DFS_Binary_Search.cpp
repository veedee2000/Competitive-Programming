class Solution {
    
    int n;
    vector<int>dr, dc;
    
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int h){
        if(i == n -1 and j == n - 1) return 1;
        vis[i][j] = 1;
        
        for(int rc = 0;rc < 4;rc++){
            int x = i + dr[rc], y = j + dc[rc];
            if(x >= 0 and y >= 0 and x < n and y < n and grid[x][y] <= h and !vis[x][y]){
                if(dfs(x, y, grid, vis, h)) return 1;
            }
        }
        
        return 0;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = max(grid[0][0], grid[n - 1][n - 1]), r = n * n - 1, m;
        dr = {0, 0, -1 , 1}, dc = {-1, 1, 0, 0};
        vector<vector<int>>vis;
        while(l <= r){
            m = l + (r - l) / 2;
            vis.clear();
            vis = vector<vector<int>>(n, vector<int>(n, 0));
            if(dfs(0, 0, grid, vis, m)) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};
