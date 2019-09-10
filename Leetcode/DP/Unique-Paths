class Solution {
    
private:
    int dp[102][102],i,j;
public:
    Solution(){
        for(i=0;i<101;i++){
            for(j=0;j<101;j++) dp[i][j] = -1;
        }
    }
    int uniquePaths(int m, int n) {
        if(m < 1 or n < 1) return 0;
        if(m == 1 and n == 1) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n] = uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};
