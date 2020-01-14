const int mod = 1000000007;

class Solution {
public:
    vector<vector<int>>dp;
    int numWays(int steps, int arrLen) {
        dp.resize(min(steps,arrLen),vector<int>(steps + 1,-1));
        return f(0,steps,min(steps,arrLen));
    }
    
    int f(int i,int N,int size){
        if(i >= size or i < 0) return 0;
        if(N < 1){
            if(i == 0) return 1;
            else return 0;
        }
        if(dp[i][N] != -1) return dp[i][N];
        return dp[i][N] = ((f(i - 1,N - 1,size) % mod + f(i + 1,N - 1,size) % mod ) % mod + f(i,N - 1,size) % mod) % mod;
    }
};
