class Solution {
public:
    vector<int>dp;
    int n;
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n,INT_MIN);
        int ans = f(0,stoneValue);
        if(ans > 0) return "Alice";
        else if(ans == 0) return "Tie";
        else return "Bob";
    }
    
    int f(int i,vector<int>&stones){
        if(i >= n) return 0;
        if(dp[i] != INT_MIN) return dp[i];
        dp[i] = max(dp[i],stones[i] - f(i + 1,stones));
        if(i + 1 < n) dp[i] = max(dp[i],stones[i] + stones[i + 1] - f(i + 2,stones));
        if(i + 2 < n) dp[i] = max(dp[i],stones[i] + stones[i + 1] + stones[i + 2] - f(i + 3,stones));
        return dp[i];
    }
};
