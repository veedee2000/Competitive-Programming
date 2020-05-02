class Solution {
public:
    vector<vector<int>>dp;
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        dp.resize(n,vector<int>(m + 1,-1));
        return f(n - 1,m,nums);
    }
    
    int f(int i,int subRem,vector<int>& nums){
        if(i < 0) return (subRem == 0) ? 0 : INT_MAX;
        if(subRem == 0) return INT_MAX;
        if(dp[i][subRem] != -1) return dp[i][subRem];
        int currSum = 0,minSum = INT_MAX;
        for(int j = i;j >= subRem - 1;j--){
            currSum += nums[j];
            minSum = min(minSum,max( currSum, f(j - 1,subRem - 1,nums) ));
        }
        return dp[i][subRem] = minSum;
    }
};
