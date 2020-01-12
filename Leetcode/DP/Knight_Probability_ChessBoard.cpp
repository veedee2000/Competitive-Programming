class Solution {
public:
    vector<vector<vector<double>>>dp;
    vector<int>dr,dc;
    double knightProbability(int N, int K, int r, int c) {
        dp.resize(N,vector<vector<double>>(N,vector<double>(K + 1, 0)));
        dr = {2, 2, 1, 1, -1, -1, -2, -2};
        dc = {1, -1, 2, -2, 2, -2, 1, -1};
        return f(r,c,K,N);
    }
    
    double f(int i,int j,int K,int N){
        if(i < 0 or j < 0 or i >= N or j >= N) return 0;
        if(K == 0) return 1;
        if(dp[i][j][K] > 0) return dp[i][j][K];
        double ans = 0;
        for(int rc = 0;rc < dr.size();rc++){
            ans += f(i + dr[rc],j + dc[rc],K - 1,N);
        }
        return dp[i][j][K] = ans / 8;
    }
};
