class Solution {
public:
    string s;
    vector<vector<int>>dp;
    int longestPalindromeSubseq(string s) {
        this -> s = s;
        dp.resize(s.size(),vector<int>(s.size(), -1));
        return f(0,s.size() - 1);
    }
    
    int f(int i,int j){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return dp[i][j] = max(f(i + 1,j),f(i,j - 1));
        return dp[i][j] = 2 + f(i + 1,j - 1);
    }
};
