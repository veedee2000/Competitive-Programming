class Solution {
public:
    int dp[1000][1000];
    int function(int i, int j){
        if(i >= j) return 0;
        if(dp[i][j]) return dp[i][j];
        int value = INT_MAX;
        for(int k = i;k <= j;k++){
            value = min(value, k + max(function(i, k - 1), function(k + 1, j)));
        }
        return dp[i][j] = value;
    }
    
    int getMoneyAmount(int n) {
        memset(dp,0,sizeof(dp));
        return function(1,n);
    }
};
