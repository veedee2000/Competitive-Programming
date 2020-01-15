class Solution {
public:
    vector<int>dp;
    int numTrees(int n) {
        dp.resize(n + 1,-1);
        return f(n);
    }
    
    int f(int i){
        if(i < 2) return 1;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j = 1;j <= i;j++) ans += f(j - 1) * f(i - j);
        return dp[i] = ans;
    }
};
