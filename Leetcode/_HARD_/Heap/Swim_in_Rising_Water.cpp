#define t tuple<int, int, int>

class Solution {
    
    struct comp{
        bool operator()(t& a, t& b){
            return get<0>(a) > get<0>(b);
        }
    };
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<t, vector<t>, comp>pq;
        pq.push({grid[0][0], 0, 0});
        vector<int>dr = {0, 0, -1, 1}, dc = {-1, 1, 0, 0};
        int ans = 0;
        while(!pq.empty()){
            auto [val, i, j] = pq.top();
            ans = max(ans, val);
            pq.pop();
            if(i == n - 1 and j == n - 1) break;
            for(int rc = 0;rc < 4;rc++){
                int x = i + dr[rc], y = j + dc[rc];
                if(x >= 0 and y >= 0 and x < n and y < n and grid[x][y] > -1){
                    pq.push({grid[x][y], x, y});
                    grid[x][y] = -1;
                }
            }
        }
        
        return ans;
    }
};
