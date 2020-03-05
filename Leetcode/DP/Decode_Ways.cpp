class Solution {
public:
    vector<int>dp;
    int n;
    string s;
    int numDecodings(string s) {
        n = s.size();
        this -> s = s;
        dp.resize(n, -1);
        return f(0);
    }
    
    int f(int i){
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(i == n - 1) return 1;
        if(dp[i] != -1) return dp[i];
        int ans = f(i + 1);
        string sub;
        sub.push_back(s[i]);
        sub.push_back(s[i + 1]);
        if(stoi(sub) <= 26) ans += f(i + 2);
        return dp[i] = ans;
    }
};
