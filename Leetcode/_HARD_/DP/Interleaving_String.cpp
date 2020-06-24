class Solution {
    
    vector<vector<int>>dp;
    int m, n;
    
    bool f(int i, int j, string& s1, string& s2, string& s3){
        if(i + j == s3.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(i < s1.size() and s1[i] == s3[i + j]){
            if( f(i + 1, j, s1, s2, s3) ) return dp[i][j] = 1;
        }
        if(j < s2.size() and s2[j] == s3[i + j]){
            if( f(i, j + 1, s1, s2, s3) ) return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size(), n = s2.size();
        if(s3.size() != m + n) return 0;
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return f(0, 0, s1, s2, s3);
    }
};
