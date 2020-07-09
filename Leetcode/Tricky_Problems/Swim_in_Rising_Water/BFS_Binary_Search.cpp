class Solution {
    
    int n;
    vector<int>dr, dc;
    
    bool bfs(vector<vector<int>>& grid, int h){
        queue<int>q;
        q.push(0);
        vector<vector<int>>vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int currX = curr / n, currY = curr % n;
            if(currX == n - 1 and currY == n - 1) return 1;
            for(int rc = 0;rc < 4;rc++){
                int x = currX + dr[rc], y = currY + dc[rc];
                if(x >= 0 and y >= 0 and x < n and y < n and grid[x][y] <= h and !vis[x][y]){
                    q.push(x * n + y);
                    vis[x][y] = 1;
                }
            }
        }
        return 0;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int l = grid[0][0], r = INT_MAX, m;
        dr = {0, 0, -1 , 1}, dc = {-1, 1, 0, 0};
        n = grid.size();
        while(l <= r){
            m = l + (r - l) / 2;
            if(bfs(grid, m)) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};
