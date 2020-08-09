#define t tuple<int, int, int>

class Solution {
    
    struct comp{
        bool operator()(t& a, t& b){
            return get<0>(a) > get<0>(b);
        }
    };
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if(!m or !n) return {};
        k = min(m * n, k);
        vector<vector<int>>ans;
        priority_queue<t, vector<t>, comp>pq;
        for(int i = 0;i < m;i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        while(k--){
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if(j + 1 < n) pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
        return ans;
    }
};
