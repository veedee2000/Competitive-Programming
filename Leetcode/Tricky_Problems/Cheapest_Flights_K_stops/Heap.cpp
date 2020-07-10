#define ti tuple<int,int,int>

class Solution {
    
    struct comp{
        bool operator()(ti a, ti b){
            return get<0>(a) > get<0>(b); 
        }
    };
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        vector<vector<pair<int,int>>>adj(n);
        for(auto edge:flights) adj[edge[0]].emplace_back(edge[1], edge[2]);
        priority_queue<ti, vector<ti>, comp>pq;
        pq.emplace(0, src, 0);
        while(!pq.empty()){
            auto [cost, pos, stops] = pq.top();
            pq.pop();
            if(pos == dst) return cost;
            if(stops == k) continue;
            for(auto next:adj[pos]){
                auto [nextNode, w] = next;
                pq.emplace(cost + w, nextNode, stops + 1);
            }
        }
        return -1;
    }
};
