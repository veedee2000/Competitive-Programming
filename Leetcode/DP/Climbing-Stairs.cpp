class Solution {
private:
    int dp[1001],i;
public:
    Solution() {
        for(i=0;i<1000;i++) dp[i] = -1;
        // memset(dp,-1,sizeof(dp));
    }
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n]!= -1) return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};
