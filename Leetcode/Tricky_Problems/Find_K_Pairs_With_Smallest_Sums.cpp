class Solution {
    
    struct comp{
        bool operator()(vector<int>& a,vector<int>& b){
            return a[0] > b[0];
        }
    };
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,comp>heap;
        int m = nums1.size(), n = nums2.size();
        if(!m or !n) return {};
        for(int i = 0;i < m;i++) heap.push({nums1[i] + nums2[0],i,0});
        vector<vector<int>>ans;
        while(k-- and !heap.empty()){
            vector<int>curr = heap.top();
            heap.pop();
            ans.push_back({nums1[curr[1]],nums2[curr[2]]});
            if(curr[2] < n - 1) heap.push({nums1[curr[1]] + nums2[curr[2] + 1],curr[1],curr[2] + 1}); 
        }
        return ans;
    }
};
