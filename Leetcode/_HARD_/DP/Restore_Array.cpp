class Solution {
    
    const int mod = 1e9 + 7;
    
public:
    vector<int>dp;
    int numberOfArrays(string s, int k) {
        dp.resize(s.size(),-1);
        return f(s,0,k);
    }
    
    int f(string& s,int i,int k){
        if(i >= s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        long long val = 0,ans = 0;
        for(int j = i;j < s.size();j++){
            val = val * 10 + int (s[j] - '0');
            if(val > k) break;
            ans = (ans + f(s,j + 1,k)) % mod;
        }
        return dp[i] = ans;
    }
};
