class Solution {
public:
    queue<vector<int>>q;
    vector<int>dr,dc;
    int ans;
    int orangesRotting(vector<vector<int>>& grid) {
        dr = {-1,1,0,0};
        dc = {0,0,1,-1};
        
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[i].size();j++){
                if(grid[i][j] == 2){
                    grid[i][j] = 3;
                    q.push({i,j,0});
                }
            }
        }
        
        ans = 0;
        bfs(grid);
        
        for(auto x:grid){
            for(auto y:x){
                if(y == 1) return -1;
            }
        }
        
        return ans;
    }
    
    void bfs(vector<vector<int>>& grid){
        while(!q.empty()){
            int curr_x = q.front()[0];
            int curr_y = q.front()[1];
            int parentVal = q.front()[2];
            q.pop();
            for(int rc = 0;rc < 4;rc++){
                int x = curr_x + dr[rc];
                int y = curr_y + dc[rc];
                int val = parentVal;
                if(x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size()){
                    if(grid[x][y] == 2){
                        grid[x][y] = 3;
                        q.push({x,y,val});
                    }
                    else if(grid[x][y] == 1){
                        grid[x][y] = 3;
                        q.push({x,y,++val});
                    }
                    ans = max(ans,val);
                }
            }
        }
    }
    
};
