class Solution {
    vector<vector<int>>dp;
    
    int f(int n, bool b){
        if(n == 2) return b ? 2 : 1;
        if(dp[n][b] != -1) return dp[n][b];
        int ans = (b ? n : 0);
        for(int i = n - 1;i >= 2;i--) ans = max(ans, (n - i) * f(i, 1));
        return dp[n][b] = ans;
    }
    
public:
    int integerBreak(int n) {
        dp.resize(n + 1, vector<int>(2, -1));
        return f(n, 0);
    }
};
