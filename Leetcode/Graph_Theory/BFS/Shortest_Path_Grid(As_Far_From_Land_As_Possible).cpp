class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid.size();j++){
                if(grid[i][j]) q.push({i,j});
            }
        }
        
        vector<pair<int,int>>dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int ans = -1;
        
        while(!q.empty()){
            pair<int,int>curr = q.front();
            q.pop();
            for(auto dir:dirs){
                int row = curr.first + dir.first;
                int column = curr.second + dir.second;
                if(row >= 0 and row < grid.size() and column >= 0 and column < grid.size() and grid[row][column] == 0){
                    grid[row][column] = 1 + grid[curr.first][curr.second];
                    q.push({row,column});
                    ans = max(ans, grid[row][column]);
                }
            }
        }
        return (ans > 0 ? ans - 1 : -1);
    }
};
