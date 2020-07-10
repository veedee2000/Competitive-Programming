
class Solution {
    
    const int INF = (int) 1e9;
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        vector<int>dist(n, INF);
        dist[src] = 0;
        int ans = INF;
        for(int i = 0;i < k;i++){
            vector<int>temp = dist;
            for(auto edge:flights){
                int u = edge[0], v = edge[1], w = edge[2];
                if(dist[u] != INF) temp[v] = min(temp[v], dist[u] + w);
            }
            dist = temp;
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};
