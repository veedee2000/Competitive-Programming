// Gets TLE with this Approach.

#define p pair<int, int>

class Solution {
    
    struct comp{
        bool operator()(p& a, p& b){
            return a.first * a.second > b.first * b.second;
        }
    };
    
public:
    int findKthNumber(int m, int n, int k) {
        if(m > n) swap(m, n);
        priority_queue<p, vector<p>, comp>pq;
        for(int i = 1;i <= m;i++) pq.push({i, 1});
        while(--k){
            auto [i, j] = pq.top();
            pq.pop();
            if(j + 1 <= n) pq.push({i, j + 1});
        }
        int ans = pq.top().first * pq.top().second;
        return ans;
    }
};
