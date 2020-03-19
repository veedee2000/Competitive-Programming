class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        int pre = 0;
        for(int i = 0;i < nums.size();i++){
            pre += nums[i];
            mp[pre].push_back(i);
        }
        
        int ans = mp[k].size();
        int toBeFound;
        pre = 0;
        for(int i = 0;i < nums.size() - 1;i++){
            pre += nums[i];
            toBeFound = k + pre;
            auto it = upper_bound(mp[toBeFound].begin(),mp[toBeFound].end(),i);
            if(it != mp[toBeFound].end()){
                int index = it - mp[toBeFound].begin();
                ans += mp[toBeFound].size() - index;
            }
        }
        
        return ans;
    }
};
