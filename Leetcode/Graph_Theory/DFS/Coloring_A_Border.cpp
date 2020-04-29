class Solution {
public:
    vector<int>dr = {0,0,-1,1},dc = {-1,1,0,0};
    int color,prevColor,m,n;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        this -> color = color;
        if(grid[r0][c0] == color) return grid;
        m = grid.size(),n = grid[0].size();
        prevColor = grid[r0][c0];
        dfs(r0,c0,grid);
        for(auto& vec:grid){
            for(auto& element:vec){
                if(element == 1001) element = color;
                else if(element == 0) element = prevColor;
            }
        }
        return grid;
    }
    
    void dfs(int i,int j,vector<vector<int>>& grid){
        bool c = 0;
        for(int rc = 0;rc < 4;rc++){
            if(!check(i + dr[rc],j + dc[rc],grid)) { c = 1; break; }
        }
        if(c) grid[i][j] = 1001;
        else grid[i][j] = 0;
        for(int rc = 0;rc < 4;rc++){
            int x = i + dr[rc],y = j + dc[rc];
            if(x >= 0 and y >= 0 and x < m and y < n and grid[x][y] == prevColor) dfs(x,y,grid); 
        }
    }
    
    bool check(int i,int j,vector<vector<int>>& grid){
        if(i < 0 or j < 0 or i >= m or j >= n) return 0;
        if(grid[i][j] == prevColor or grid[i][j] == 1001 or grid[i][j] == 0) return 1;
        return 0;
    } 
};
