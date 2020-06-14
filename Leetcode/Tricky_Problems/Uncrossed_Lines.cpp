class Solution {
    
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>>dp(2,vector<int>(B.size(),0));
        for(int i = 0;i < B.size();i++)  dp[0][i] = max(int (A[0] == B[i]), (i == 0 ? 0 : dp[0][i - 1]));
        for(int i = 1;i < A.size();i++){
            for(int j = 0;j < B.size();j++){
                if(A[i] == B[j]) dp[1][j] = 1 + (j == 0 ? 0 : dp[0][j - 1]);
                else dp[1][j] = max(j == 0 ? 0 : dp[1][j - 1], dp[0][j]);
            }
            dp[0] = dp[1];
        }
        return dp[0][B.size() - 1];
    }
};
