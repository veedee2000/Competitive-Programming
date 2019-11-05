class Solution {
public:
    vector<vector<int>>dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(), vector<int>(text2.size(), -1));
        return f(text1.size() - 1,text2.size() - 1,text1,text2);
    }
    
    int f(int i,int j,string &s1, string &s2){
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) dp[i][j] = 1 + f(i - 1, j - 1, s1, s2);
        else dp[i][j] = max(f(i - 1, j, s1, s2), f(i, j - 1, s1, s2));
        return dp[i][j];
    }
};
