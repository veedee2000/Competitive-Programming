// O(n) Bottom Up

class Solution {
    
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>>dp(2, vector<int>(n + 1, 0));
        
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(A[i - 1] == B[j - 1]) dp[1][j] = 1 + dp[0][j - 1];
                else dp[1][j] = max(dp[0][j], dp[1][j - 1]);
            }
            dp[0] = dp[1];
        }
        
        return dp[0][n];
    }
};

// O(n ^ 2) Recursive

class Solution {
    
    vector<vector<int>>dp;
    int m, n;
    
    int f(int i,int j,vector<int>& A, vector<int>& B){
        if(i == m or j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(A[i] == B[j]) dp[i][j] = 1 + f(i + 1, j + 1, A, B);
        else dp[i][j] = max(f(i + 1, j, A, B), f(i, j + 1, A, B));
        return dp[i][j];
    }
    
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        m = A.size(), n = B.size();
        dp.resize(m, vector<int>(n, -1));
        return f(0, 0, A, B);
    }
};

// O(n ^ 2) Bottom Up

class Solution {
    
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(A[i - 1] == B[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[m][n];
    }
};

// Done 1
