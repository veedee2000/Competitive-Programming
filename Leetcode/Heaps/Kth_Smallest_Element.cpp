#define t tuple<int, int, int>
class Solution {
    
    struct comp{
        bool operator()(const t& a, const t& b){
            return get<0>(a) > get<0>(b);
        }
    };
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<t, vector<t>, comp>pq;
        for(int i = 0;i < n;i++) pq.push({matrix[i][0], i, 0});
        while(--k){
            auto [val, i, j] = pq.top();
            pq.pop();
            if(j + 1 < n) pq.push({matrix[i][j + 1], i, j + 1});
        }
        return get<0>(pq.top());
    }
};
