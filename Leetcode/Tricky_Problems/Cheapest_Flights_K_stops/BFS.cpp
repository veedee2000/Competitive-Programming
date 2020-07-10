#define pr pair<int,int>

class Solution {
    
    const int INF = (int) 1e9;
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        vector<vector<pr>>adj(n);
        vector<int>dist(n, INF);
        for(auto edge:flights) adj[edge[0]].emplace_back(edge[1], edge[2]);
        queue<pr>q;
        q.emplace(0, src);
        dist[src] = 0;
        int stops = k, ans = INF;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [cost, pos] = q.front();
                q.pop();
                if(pos == dst) ans = min(ans, cost);
                for(auto next:adj[pos]){
                    auto [nextNode, w] = next;
                    if(dist[nextNode] > cost + w) dist[nextNode] = cost + w, q.emplace(dist[nextNode], nextNode);
                }
            }
            if(stops-- == 0) break;
        }
        return ans == INF ? -1 : ans;
    }
};
