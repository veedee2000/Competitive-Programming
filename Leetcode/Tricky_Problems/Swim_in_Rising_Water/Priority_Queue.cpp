class Solution {
    
    struct comp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0] > b[0]; 
        }
    }; 
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, comp>pq;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;
        vector<int>dr = {0, 0, -1, 1}, dc = {-1, 1, 0, 0};
        int ans = 0;
        while(!pq.empty()){
            vector<int>curr = pq.top();
            pq.pop();
            int i = curr[1], j = curr[2];
            ans = max(ans, curr[0]);
            if(i == n - 1 and j == n - 1) break;
            for(int rc = 0;rc < 4;rc++){
                int x = i + dr[rc], y = j + dc[rc];
                if(x >= 0 and y >= 0 and x < n and y < n and !vis[x][y]){
                    pq.push({grid[x][y], x, y});
                    vis[x][y] = 1;
                }
            }
        }
        return ans;
    }
};
