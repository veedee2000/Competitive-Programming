class Solution {
    
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(2, vector<int>(n, 0));
        
        for(int i = n - 1;i >= 0;i--){
            for(int j = i + 1;j < n;j++){
                if(s[i] == s[j]) dp[1][j] = j == i + 1 ? 0 : dp[0][j - 1];
                else dp[1][j] = j == i + 1 ? (s[i] != s[j]) : 1 + min(dp[0][j], dp[1][j - 1]);
            }
            dp[0] = dp[1];
        }
        
        return dp[0][n - 1];
    }
};
