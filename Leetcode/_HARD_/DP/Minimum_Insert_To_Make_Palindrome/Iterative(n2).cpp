class Solution {
    
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i = 1;i < n;i++) dp[i - 1][i] = !(s[i - 1] == s[i]);
        for(int i = n - 1;i >= 0;i--){
            for(int j = i + 2;j < n;j++){
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        } 
        
        return dp[0][n - 1];
    }
};