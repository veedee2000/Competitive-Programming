class Solution {
public:
    vector<vector<int>>dp;
    int ans;
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        ans = 0;
        dp.resize(matrix.size(),vector<int>(matrix[0].size(), -1));
        f(matrix.size() - 1,matrix[0].size() - 1,matrix);
        return ans * ans;
    }
    
    int f(int i,int j,vector<vector<char>>& matrix){
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = f(i - 1,j,matrix);
        int left = f(i,j - 1,matrix);
        int diagonal = f(i - 1,j - 1,matrix);
        if(matrix[i][j] == '0') return 0;
        dp[i][j] = 1 + min({up,left,diagonal});
        ans = max(ans,dp[i][j]);
        return dp[i][j];
    }
};
