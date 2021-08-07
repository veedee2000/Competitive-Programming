class Solution {
    
    int cal(vector<int>& a, vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<bool>vis(n, 0);
        vis[0] = 1;
        for(int i = 1;i < n;i++){
            pq.push({cal(points[0], points[i]), i});
        }
        int ans = 0;
        while(!pq.empty()){
            auto [val, curr] = pq.top();
            pq.pop();
            if(!vis[curr]){
                vis[curr] = 1;
                ans += val;
                for(int i = 0;i < n;i++){
                    if(!vis[i]){
                        pq.push({cal(points[i], points[curr]), i});
                    }
                }
            }
        }
        return ans;
    }
};
