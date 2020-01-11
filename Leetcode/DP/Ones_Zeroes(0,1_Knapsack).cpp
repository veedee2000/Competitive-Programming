const int INF = 10000000;

class Solution {
public:
    vector<vector<vector<int>>>dp;
    vector<pair<int,int>>v;
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size());
        for(auto &x:dp) x.resize(m + 1, vector<int>(n + 1,-1));
        for(auto x:strs){
            int zero = 0,one = 0;
            for(auto y:x){
                if(y == '0') zero++;
                else one++;
            }
            v.push_back({zero,one});
        }
        return f(v.size() - 1,m,n);
    }
    
    int f(int i,int zero,int one){
        if(zero < 0 or one < 0) return -INF;
        if(i < 0) return 0;
        if(zero == 0 and one == 0) return 0;
        if(dp[i][zero][one] != -1) return dp[i][zero][one];
        return dp[i][zero][one] = max(f(i - 1,zero,one),1 + f(i - 1,zero - v[i].first,one - v[i].second));
    }
};
