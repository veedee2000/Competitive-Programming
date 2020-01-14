const int mod = 1000000007;

class Solution {
public:
    vector<vector<vector<int>>>dp;
    vector<int>dr,dc;
    int findPaths(int m, int n, int N, int i, int j) {
        dr = {1,-1,0,0};
        dc = {0,0,-1,1};
        dp.resize(m,vector<vector<int>>(n,vector<int>(N + 1,-1)));
        return f(m,n,i,j,N);
    }
    
    int f(int m,int n,int i,int j,int N){
        if(i < 0 or j < 0 or i >= m or j >= n) return 1;
        if(N < 1) return 0;
        if(dp[i][j][N] != -1) return dp[i][j][N];
        int ans = 0;
        for(int rc = 0;rc < dc.size();rc++) ans = (ans + f(m,n,i + dr[rc],j + dc[rc],N - 1)) % mod;
        return dp[i][j][N] = ans;
    }
};
