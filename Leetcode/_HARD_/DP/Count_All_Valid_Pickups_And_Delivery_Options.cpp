const int mod = 1000000007;

class Solution {
public:
    vector<vector<long long>>dp;
    int countOrders(int n) {
        dp.resize(n + 1,vector<long long>(n + 1,-1));
        return f(0,n);
    }
    
    long long f(int ones,int twos){
        if(ones + twos < 1) return 1;
        if(dp[ones][twos] != -1) return dp[ones][twos];
        return dp[ones][twos] = (((ones > 0) ? ones * (f(ones - 1,twos)) % mod : 0) % mod + ((twos > 0) ? twos * (f(ones + 1,twos - 1)) % mod : 0) % mod) % mod;
    }
};
