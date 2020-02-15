class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<int>dr = {0,0,-1,1,-1,1,1,-1},dc = {-1,1,0,0,1,-1,1,-1};
        queue<int>q;
        if(grid[0][0] == 0) q.push(0);
        int ans = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int it = 0;it < sz;it++){
                int curr = q.front();
                q.pop();
                if(curr == n * m - 1) return ans;
                int x = curr / n,y = curr % n;
                for(int rc = 0;rc < 8;rc++){
                    int x1 = x + dr[rc],y1 = y + dc[rc];
                    if(x1 >= 0 and y1 >= 0 and x1 < m and y1 < n and grid[x1][y1] == 0){
                        q.push(x1 * n + y1);
                        grid[x1][y1] = -1;
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
