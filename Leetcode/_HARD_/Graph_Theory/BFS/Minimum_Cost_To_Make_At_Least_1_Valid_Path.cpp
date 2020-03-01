class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        q.push({0,0});
        unordered_map<int,unordered_map<int,int>>mp;
        vector<int>dr = {0,0,1,-1},dc = {1,-1,0,0};
        mp[0][0] = 0;
        int ans = INT_MAX;
        while(!q.empty()){
            pair<int,int>curr = q.front();
            q.pop();
            int i = curr.first / grid[0].size(), j = curr.first % grid[0].size();
            if(i == grid.size() - 1 and j == grid[0].size() - 1) ans = min(ans,curr.second);
            for(int rc = 0;rc < 4;rc++){
                int x = i + dr[rc],y = j + dc[rc];
                if(x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size()){
                    
                    if(rc + 1 == grid[i][j]){
                        if(!mp[x].count(y) or mp[x][y] > curr.second) q.push({x * grid[0].size() + y,curr.second}),mp[x][y] = curr.second;
                    }
                    else{
                        if(!mp[x].count(y) or mp[x][y] > curr.second + 1) q.push({x * grid[0].size() + y,curr.second + 1}),mp[x][y] = curr.second + 1;
                    }
                }
            }
        }
        return ans;
    }
};
