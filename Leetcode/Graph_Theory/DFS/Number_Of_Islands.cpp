class Solution {
public:
    vector<vector<bool>>vis;
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()) return 0;
        vis.resize(grid.size(), vector<bool>(grid[0].size(), 0));
        int ans = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    dfs(i,j,grid);
                    ++ans;
                }
            }
        }
        return ans;
    }
    
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i >= grid.size() or i < 0 or j >= grid[0].size() or j < 0) return;
        vis[i][j] = 1;
        if(grid[i][j] == '0') return;
        if(i < grid.size() - 1){
            if(!vis[i + 1][j]) dfs(i + 1,j,grid);
        }
        if(j < grid[0].size() - 1){
            if(!vis[i][j + 1]) dfs(i,j + 1,grid);
        }
        if(i > 0){
            if(!vis[i - 1][j]) dfs(i - 1,j,grid);
        }
        if(j > 0){
            if(!vis[i][j - 1]) dfs(i,j - 1,grid);
        }
    }
};
