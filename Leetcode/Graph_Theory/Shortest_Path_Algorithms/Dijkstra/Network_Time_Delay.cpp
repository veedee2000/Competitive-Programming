#define INF 6000000
class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int>d,p;
    int N,ans = 0;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        adj.resize(N + 1);
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        this -> N = N;
        d.resize(N + 1, INF);
        p.resize(N + 1, -1);
        dijkstra(K);
        for(int i = 1;i <= N;i++){
            if(d[i] == INF) return -1;
            ans = max(ans,d[i]);
        }
        return ans;
    }
    
    void dijkstra(int K){
        vector<bool>u(N + 1,0);
        d[K] = 0;
        for(int i = 1;i <= N;i++){
            int v = -1;
            for(int j = 1;j <= N;j++){
                if(!u[j] and (v == -1 or d[j] < d[v])) v = j;
            }
            if(d[v] == INF) break;

            u[v] = 1;
            for(auto edge : adj[v]){
                int to = edge.first;
                int len = edge.second;

                if(d[v] + len < d[to]){
                    d[to] = d[v] + len;
                    p[to] = v;
                }
            }
        }
    }
    
};
