class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        unordered_map<int,int>vis;
        pq.push({0,0});
        vector<int>dr = {0,0,1,-1},dc = {1,-1,0,0};
        while(!pq.empty()){
            auto [cost,val] = pq.top();
            pq.pop();
            if(vis[val]) continue;
            vis[val] = 1;
            int i = val / grid[0].size(), j = val % grid[0].size();
            if(i == grid.size() - 1 and j == grid[0].size() - 1) return cost;
            for(int rc = 0;rc < 4;rc++){
                int x = i + dr[rc],y = j + dc[rc];
                if(x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size()){
                    
                    if(rc + 1 == grid[i][j]){
                        pq.push({cost,x * grid[0].size() + y});
                    }
                    else{
                        pq.push({cost + 1,x * grid[0].size() + y});
                    }
                }
            }
        }
        return 0;
    }
};
