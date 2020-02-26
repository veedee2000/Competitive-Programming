class Solution {
public:
    vector<vector<vector<int>>>dp;
    string s;
    int palindromePartition(string s, int k) {
        this -> s = s;
        int n = s.size();
        dp.resize(n);
        for(auto &x:dp){
            x.resize(n);
            for(auto &y:x){
                y.resize(k + 1,-1);
            }
        }
        return f(0,n - 1,k);
    }
    
    int f(int begin,int end,int k){
        if(begin > end) return INT_MAX;
        if(end - begin + 1 < k) return INT_MAX;
        if(k == 1){
            int ret = 0;
            for(int i = begin;i <= end;i++){
                if(s[i] != s[end + begin - i]) ret++;
            }
            return ret / 2;
        }
        if(dp[begin][end][k] != -1) return dp[begin][end][k];
        int ans = INT_MAX;
        for(int i = begin;i <= end;i++){
            for(int k1 = 1;k1 < k;k1++){
                int val1 = f(begin,i,k1),val2 = f(i + 1,end,k - k1);
                if(val1 != INT_MAX and val2 != INT_MAX) ans = min(ans,val1 + val2);
            }
        }
        return dp[begin][end][k] = ans;
    }
};
