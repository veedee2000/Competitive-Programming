class Solution {
    vector<vector<int>>dp;
    
    int f(int i,int j,string& s){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans;
        if(s[i] == s[j]) ans = f(i + 1, j - 1, s);
        else ans = min(1 + f(i + 1, j, s), 1 + f(i, j - 1, s));
        return dp[i][j] = ans;
    }
    
public:
    int minInsertions(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return f(0, n - 1, s);
    }
};
