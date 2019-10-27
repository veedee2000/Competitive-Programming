class Solution {
public:
    int dp[1100];
    bool divisorGame(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
    
    int f(int i){
        if(i == 1) return 0;
        if(dp[i] != -1) return dp[i];
        bool c = 1;
        for(int j = 1;j < i;j++){
            if(i%j == 0) c &= f(i - j); 
        }
        return dp[i] = !c;
    }
};
