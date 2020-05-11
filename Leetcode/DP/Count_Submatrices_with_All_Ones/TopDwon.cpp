class Solution {
    vector<vector<int>>dp;
    int m,n;
public:
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        dp.resize(m,vector<int>(n,-1));
        f(m - 1,n - 1,matrix);
        int ans = 0;
        for(auto &vec:dp){
            for(auto &element:vec){
                ans += element;
            }
        } 
        
        return ans;
    }
    
    int f(int i,int j,vector<vector<int>>& matrix){
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = f(i,j - 1,matrix), right = f(i - 1,j,matrix), diagonal = f(i - 1,j - 1,matrix);
        if(!matrix[i][j]) return dp[i][j] = 0;
        return dp[i][j] = 1 + min({left, right, diagonal});
    }
};
