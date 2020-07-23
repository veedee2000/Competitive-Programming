class Solution {
    
    vector<int>dp;
    
    int f(int state, int n){
        if(n == 0) return 1;
        if(dp[state] != -1) return dp[state];
        int ans = 0;
        for(int i = (n == 1);i < 10;i++){
            if(state & (1 << i)) continue;
            ans += f(state | (1 << i), n - 1);
        }
        return dp[state] = ans;
    }
    
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        for(int i = 0;i <= n;i++){
            dp.clear();
            dp.resize(1 << 10, -1);
            ans += f(0, i);
        }
        return ans;
    }
};
