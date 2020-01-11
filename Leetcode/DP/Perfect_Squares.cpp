class Solution {
public:
    vector<int>dp;
    int numSquares(int n){
        dp.resize(n + 1,-1);
        return f(n);
    }
    
    int f(int n){ 
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i = 1;i * i <= n;i++){
            ans = min(ans,f(n - i * i));
        }
        return dp[n] = 1 + ans;
    }
};
