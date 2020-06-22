class Solution {
    vector<int>dp;
    
    int f(int n){
        if(n < 4) return n;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MIN;
        for(int i = n - 1;i >= 2;i--) ans = max(ans, (n - i) * f(i));
        return dp[n] = ans;
    }
    
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2; 
        dp.resize(n + 1, -1);
        return f(n);
    }
};
