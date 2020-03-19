class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int pre = 0,ans = 0;
        for(auto x:nums){
            pre += x;
            if(pre == k) ans++;
            ans += mp[pre - k];
            mp[pre]++;
        }
        return ans;
    }
};
