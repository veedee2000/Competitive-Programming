class Solution {
    vector<vector<int>> grid;
    bool c;
public:
    int closedIsland(vector<vector<int>>& grid) {
        this -> grid = grid;
        int ans = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(!this -> grid[i][j]){
                    c = 1;
                    dfs(i,j);
                    ans += c;
                }
            }
        }
        return ans;
    }
    
    void dfs(int i,int j){
        if(i == 0 or i == grid.size() - 1 or j == 0 or j == grid[0].size() - 1) {c = 0; return;}
        int a[][2] = {{i + 1,j},{i,j + 1},{i - 1,j},{i,j - 1}};
        for(int x = 0;x < 4;x++){
            int x_c = a[x][0], y_c = a[x][1];
            if(x_c >= 0 and x_c < grid.size() and y_c >= 0 and y_c < grid[0].size() and grid[x_c][y_c] == 0){
                grid[x_c][y_c] = -1;
                dfs(x_c,y_c);
            }
        }
    }
};
