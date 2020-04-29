class Solution {
public:
    int ans = 0;
    vector<int>dr,dc;
    int islandPerimeter(vector<vector<int>>& grid) {
        dr = {-1,1,0,0},dc = {0,0,-1,1};
        if(!grid.size()) return 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                dfs(i,j,grid);
            }
        }
        return ans;
    }
    
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size()) return;
        if(grid[i][j] < 1) return;
        grid[i][j] = -1;
        for(int rc = 0;rc < 4;rc++){
            ans += check(i + dr[rc],j + dc[rc],grid);
            dfs(i + dr[rc],j + dc[rc],grid);
        }
    }
    
    bool check(int i,int j,vector<vector<int>>& grid){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size()) return 1;
        return grid[i][j] == 0;
    }
};
