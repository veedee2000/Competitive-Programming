class Solution {
public:
    vector<vector<int>>dp,palin;
    string s;
    int n;
    int palindromePartition(string s, int k) {
        this -> s = s;
        n = s.size();
        dp.resize(n,vector<int>(k + 1,n + 1));
        palin.resize(n,vector<int>(n,0));
        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                for(int k1 = i;k1 <= j;k1++){
                    if(s[k1] != s[j - k1 + i]) palin[i][j]++;
                }
                palin[i][j] /= 2;
            }
        }
        return f(0,k);
    }
    
    int f(int i,int k){
        if(k == 1) return palin[i][n - 1];
        if(dp[i][k] != n + 1) return dp[i][k];
        for(int j = i;j < s.size();j++){
            if(s.size() - j < k) break;
            dp[i][k] = min(dp[i][k],palin[i][j] + f(j + 1,k - 1));
        }
        return dp[i][k];
    }
};
