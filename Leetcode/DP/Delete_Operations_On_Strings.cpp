class Solution {
    vector<vector<int>>dp;
    int m, n;
public:
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();
        dp.resize(m,vector<int>(n, -1));
        return f(0,0,word1,word2);
    }
    
    int f(int i,int j,string& s1,string& s2){
        if(i == m or j == n) return (m - i) + (n - j);
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(i + 1,j + 1,s1,s2);
        return dp[i][j] = 1 + min(f(i + 1,j,s1,s2),f(i,j + 1,s1,s2));
    }
};
