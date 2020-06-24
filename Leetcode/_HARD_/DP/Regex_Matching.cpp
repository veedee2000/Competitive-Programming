class Solution {
    
    vector<vector<int>>dp;
    int m, n;
    
    bool f(int i, int j, string& s, string& p){
        if(i == s.size()){
            if(j == p.size() - 1) return 1;
            for(int index = j;index < p.size() - 1;index+=2){
                if(p[index + 1] != '*') return dp[i][j] = 0;
            }
            return dp[i][j] = 1;
        }
        if(j == p.size() - 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j + 1] == '*'){
            if(s[i] == p[j] or p[j] == '.') return dp[i][j] = f(i + 1, j, s, p) or f(i + 1, j + 2, s, p) or f(i, j + 2, s, p);
            else return dp[i][j] = f(i, j + 2, s, p);
        }
        if(s[i] == p[j] or p[j] == '.') return dp[i][j] = f(i + 1, j + 1, s, p);
        return dp[i][j] = 0;
    }
    
public:
    bool isMatch(string s, string p) {
        p.push_back('#');
        m = s.size(), n = p.size();
        dp.resize(m + 1, vector<int>(n, -1));
        return f(0, 0, s, p);
    }
};
