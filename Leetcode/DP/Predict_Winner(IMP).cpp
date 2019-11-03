class Solution {
public:
    int dp[1010][1010];
    bool PredictTheWinner(vector<int>& nums) {
        for(int i = 0;i < 1000;i++){
            for(int j = 0;j < 1000;j++){
                dp[i][j] = INT_MIN;
            }
        }
        int ans = 0;
        for(auto x:nums) ans += x;
        cout<<f(0, nums.size() - 1, nums);
        return (f(0, nums.size() - 1, nums) >= 0);
    }
    
    int f(int i, int j, vector<int>& nums){
        if(i > j) return 0;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        return dp[i][j] = max(nums[i] - f(i + 1,j,nums), nums[j] - f(i, j - 1,nums));
    }
};
