class Solution {
    vector<vector<int>>dp;
    int m, n;
    
    bool f(int i, int j, string& s, string& p){
        if(i == s.size() and j == p.size()) return 1;
        if(i == s.size()){
            for(int index = j;index < p.size();index++) if(p[index] != '*') return dp[i][j] = 0;
            return dp[i][j] = 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == s[i] or p[j] == '?') return dp[i][j] = f(i + 1, j + 1, s, p);
        if(p[j] == '*') return dp[i][j] = f(i + 1, j, s, p) or f(i + 1,j + 1, s, p) or f(i, j + 1, s, p);
        return 0;
    }
    
public:
    bool isMatch(string s, string p) {
        m = s.size(), n = p.size();
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return f(0, 0, s, p);
    }
};
