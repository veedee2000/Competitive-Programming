class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        vector<vector<int>>bucket(nums.size() + 1);
        for(auto eachPair:mp) bucket[eachPair.second].push_back(eachPair.first);
        vector<int>ans;
        for(int i = nums.size();i > 0;i--){
            for(auto members:bucket[i]){
                ans.push_back(members);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
