class Solution {
public:
    int ans = 0;
    int m,n;
    vector<int>dr = {0,0,-1,1},dc = {-1,1,0,0};
    int islandPerimeter(vector<vector<int>>& grid) {
        if(!grid.size()) return 0;
        m = grid.size(),n = grid[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1) bfs(i,j,grid);
            }
        }
        return ans;
    }
    
    void bfs(int i,int j,vector<vector<int>>& grid){
        queue<vector<int>>q;
        int x,y;
        q.push({i,j});
        grid[i][j] = -1;
        while(!q.empty()){
            vector<int>curr = q.front();
            q.pop();
            for(int rc = 0;rc < 4;rc++){
                x = curr[0] + dr[rc],y = curr[1] + dc[rc];
                ans += check(x,y,grid);
                if(x >= 0 and y >= 0 and x < m and y < n and grid[x][y] == 1){
                    q.push({x,y});
                    grid[x][y] = -1;
                }
            }
        }
    }
    
    bool check(int i,int j,vector<vector<int>>& grid){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size()) return 1;
        return grid[i][j] == 0;
    }
};
