class Solution {
public:
    vector<pair<int,int>>dp;
    int findNumberOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        dp.resize(nums.size(),{-1,1});
        int LIS = 0,ans = 0;
        f(nums.size() - 1,nums);
        for(auto x:dp) LIS = max(LIS,x.first);
        for(auto x:dp) if(x.first == LIS) ans += x.second;
        return ans;
    }
    
    int f(int i,vector<int>& nums){
        if(dp[i].first != -1) return dp[i].first;
        int ans = 1;
        for(int j = 0;j < i;j++){
            int val = f(j,nums);
            if(nums[i] > nums[j] and ans <= val + 1){
                if(ans == val + 1){
                    dp[i].second += dp[j].second;
                }
                else{
                    ans = val + 1;
                    dp[i].second = dp[j].second;
                }
            }
        }
        return dp[i].first = ans;
    }
};
