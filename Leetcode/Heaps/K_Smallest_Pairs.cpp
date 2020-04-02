class Solution {
    
    struct comp{
        bool operator()(vector<int>&a,vector<int>&b){
            return a[0] + a[1] > b[0] + b[1];
        }
    };
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(!nums1.size() or !nums2.size()) return {};
        vector<vector<int>>ans;
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        vector<int>dr = {0,1,1},dc = {1,0,1};
        pq.push({nums1[0],nums2[0],0,0});
        int m = nums1.size(),n = nums2.size();
        vector<vector<bool>>b(m,vector<bool>(n,0));
        b[0][0] = 1;
        while(!pq.empty()){
            vector<int>curr = pq.top();
            pq.pop();
            if(ans.size() == k) break;
            ans.push_back({curr[0],curr[1]});
            for(int rc = 0;rc < 3;rc++){
                int x = curr[2] + dr[rc],y = curr[3] + dc[rc];
                if(x >= 0 and y >= 0 and x < m and y < n and !b[x][y]){
                    b[x][y] = 1;
                    pq.push({nums1[x],nums2[y],x,y});
                }
            }
        }
        return ans;
    }
};
