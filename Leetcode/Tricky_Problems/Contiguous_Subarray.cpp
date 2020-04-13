class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto &x:nums) if(!x) x = -1;
        unordered_map<int,int>mp;
        int pre = 0,ans = 0;
        for(int i = 0;i < nums.size();i++){
            pre += nums[i];
            if(pre == 0) ans = i + 1;
            else{
                if(mp.count(pre)){
                    ans = max(ans,i - mp[pre]);
                }
            }
            if(!mp.count(pre)) mp[pre] = i;
        }
        return ans;
    }
};
