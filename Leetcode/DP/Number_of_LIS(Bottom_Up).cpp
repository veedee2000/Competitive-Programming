class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>>dp(nums.size(),{1,1});
        int maxSize = 1,ans = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i] and dp[i].first <= dp[j].first + 1){
                    if(dp[i].first == dp[j].first + 1) dp[i].second += dp[j].second;
                    else{
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }
                }
            }
            maxSize = max(maxSize,dp[i].first);
        }
        for(auto x:dp) if(x.first == maxSize) ans += x.second;
        return ans;
    }
};
