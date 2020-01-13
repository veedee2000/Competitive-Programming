const int mod = 1000000007;

class Solution {
public:
    vector<vector<vector<int>>>dp;
    int dieSimulator(int n, vector<int>& rollMax) {
        dp.resize(6,vector<vector<int>>(16,vector<int>(n + 1, -1)));
        int ans = 0;
        for(int i = 0;i < 6;i++) ans = (ans + f(i,rollMax[i],n,rollMax)) % mod;
        return ans;
    }
    
    int f(int i,int left,int n,vector<int>& rollMax){
        if(left <= 0) return 0;
        if(n == 1) return 1;
        if(dp[i][left][n] != -1) return dp[i][left][n];
        int val = 0;
        for(int j = 0;j < 6;j++){
            if(i == j) val = (val + f(j,left - 1,n - 1,rollMax)) % mod;
            else val = (val + f(j,rollMax[j],n - 1,rollMax)) % mod;
        }
        return dp[i][left][n] = val;
    }
};
