class Solution {
public:
    vector<vector<int>>dp;
    int minFallingPathSum(vector<vector<int>>& A) {
        int ans = INT_MAX;
        dp.resize(A.size(), vector<int>(A.size(), -1));
        for(int i = 0;i < A.size();i++){
            ans = min(ans, f(A.size() - 1,i,A));
        }
        return ans;
    }
    
    int f(int i,int j,vector<vector<int>>& A){
        if(i < 0) return 0;
        if(j < 0 or j >= A.size()) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = A[i][j] + min(f(i-1,j,A), min(f(i - 1,j + 1,A),f(i - 1,j - 1,A)));
        
    }
};
