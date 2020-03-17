class Solution {
    
    struct comp{
        bool operator()(vector<int>&a,vector<int>&b){
            return a[1] > b[1];
        }
    };
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int>dist(N + 1,INT_MAX);
        dist[0] = 0;
        dist[K] = 0;
        vector<vector<vector<int>>>v(N + 1);
        for(auto x:times){
            v[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        pq.push({K,0});
        vector<bool>b(N + 1,0);
        while(!pq.empty()){
            vector<int>curr = pq.top();
            pq.pop();
            b[curr[0]] = 1;
            for(auto x:v[curr[0]]){ 
                if(!b[x[0]]){
                    if(curr[1] + x[1] < dist[x[0]]){
                        dist[x[0]] = curr[1] + x[1];
                        pq.push({x[0],dist[x[0]]});
                    }
                }
            }
        }
        int ans = 0;
        for(auto x:dist){
            if(x == INT_MAX) return -1;
            ans = max(ans,x);
        }
        return ans;
    }
};
