class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(),ans = INT_MIN;
        vector<bool>vis(n * n,0);
        priority_queue<pair<int,int>>heap;
        vector<int>dr = {-1,1,0,0},dc = {0,0,1,-1};
        heap.push({-grid[0][0],0});
        while(!heap.empty()){
            int x = heap.top().second / n;
            int y = heap.top().second % n;
            heap.pop();
            ans = max(ans,grid[x][y]);
            if(x == n - 1 and y == n - 1) break;
            for(int i = 0;i < 4;i++){
                int xNew = x + dr[i];
                int yNew = y + dc[i];
                if(xNew >= 0 and yNew >= 0 and xNew < n and yNew < n and !vis[xNew * n + yNew]){
                    vis[xNew * n + yNew] = 1;
                    heap.push({-grid[xNew][yNew],xNew * n + yNew});
                }
            }
        }
        return ans;
    }
};
