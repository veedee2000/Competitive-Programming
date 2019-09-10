class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[target+1];
        memset(dp, 0, sizeof(dp));
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i < a) break;
                dp[i] += dp[i - a];
            }
        }
        return dp[target];
    }
};
