class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        vector<int>ans;
        for(auto x:nums) mp[x]++;
        for(auto x:mp){
            Q.push({x.second,x.first});
            if(Q.size() > k) Q.pop();
        }
        while(!Q.empty()){
            ans.push_back(Q.top().second);
            Q.pop();
        }
        return ans;
    }
};
