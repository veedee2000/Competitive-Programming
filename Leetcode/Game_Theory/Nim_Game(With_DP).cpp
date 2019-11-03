class Solution {
public:
    int dp[10000];
    bool canWinNim(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
    
    bool f(int i){
        if(i == 0) return 0;
        if(i == 1) return 1;
        if(i == 2) return 1;
        if(i == 3) return 1;
        if(dp[i] != -1) return dp[i];
        dp[i] = !(f(i-1)&f(i-2)&f(i-3));
        return dp[i];
    }
};
