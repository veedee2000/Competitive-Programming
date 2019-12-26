class Solution {
public:
    int dp[1000][1000]; 
    int n,m,ans = 0;
    vector<vector<int>>a;
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        a = mat;
        if(mat.size() == 0) return 0;
        n = mat.size(),m = mat[0].size();
        memset(dp,0,sizeof(dp));
        f(0,0,-10000,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!dp[i][j]){
                    f(i,j,-10000,0);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
    
    int f(int i,int j,int val,int dir){
        if(i < 0 or i > n - 1 or j < 0 or j > m - 1) return 0;
        if(a[i][j] <= val) return 0;
        if(dp[i][j]) return dp[i][j];
        if(dir == 0) dp[i][j] = 1 + max({f(i - 1,j,a[i][j],1),f(i + 1,j,a[i][j],2),f(i,j - 1,a[i][j],3),f(i,j + 1,a[i][j],4)});
        if(dir == 1) dp[i][j] = 1 + max({f(i - 1,j,a[i][j],1),f(i,j - 1,a[i][j],3),f(i,j + 1,a[i][j],4)});
        if(dir == 2) dp[i][j] = 1 + max({f(i + 1,j,a[i][j],2),f(i,j - 1,a[i][j],3),f(i,j + 1,a[i][j],4)});
        if(dir == 3) dp[i][j] = 1 + max({f(i - 1,j,a[i][j],1),f(i + 1,j,a[i][j],2),f(i,j - 1,a[i][j],3)});
        if(dir == 4) dp[i][j] = 1 + max({f(i - 1,j,a[i][j],1),f(i + 1,j,a[i][j],2),f(i,j + 1,a[i][j],4)});
        return dp[i][j];
    }
};
