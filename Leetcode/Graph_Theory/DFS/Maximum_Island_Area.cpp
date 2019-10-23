class Solution {
public:
    bool b[1000][1000];
    int ans = 0,n,m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(b,0,sizeof(b));
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!b[i][j]) dfs(i, j, 0, grid);
            }
        }
        return ans;
    }
    
    int dfs(int i, int j, int val, vector<vector<int>>& grid){
        b[i][j] = 1;
        if(grid[i][j] == 0) return 0;
        int v1=0, v2=0, v3=0, v4=0;
        if(i > 0 and !b[i - 1][j]){
            v1 = dfs(i - 1, j, val, grid);
        }
        
        if(i < n-1 and !b[i + 1][j]){
            v2 = dfs(i + 1, j, val, grid);
        }
            
        if(j > 0 and !b[i][j - 1]){
            v3 = dfs(i, j - 1, val, grid);
        }
        
        if(j < m-1 and !b[i][j + 1]){
            v4 = dfs(i, j + 1, val, grid);
        }
        
        ans = max(ans, 1 + v1 + v2 + v3 + v4);
        return (1 + v1 + v2 + v3 + v4);
    }
};
