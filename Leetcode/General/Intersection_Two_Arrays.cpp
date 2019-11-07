class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto x:nums1) mp[x]++;
        for(auto x:nums2) if(mp[x]) {ans.push_back(x); mp[x] = 0;}
        return ans;
    }
};
