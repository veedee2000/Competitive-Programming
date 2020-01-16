class Solution {
public:
    vector<vector<int>>dp;
    string s,t;
    int numDistinct(string s, string t) {
        this -> s = s;
        this -> t = t;
        dp.resize(s.size() + 1,vector<int>(t.size() + 1,-1));
        return f(0,0);
    }
    
    int f(int i,int j){
        if(j >= t.size()) return 1;
        if(i >= s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) dp[i][j] = f(i + 1,j) + f(i + 1,j + 1);
        if(s[i] != t[j]) dp[i][j] = f(i + 1,j);
        return dp[i][j];
    }
};
