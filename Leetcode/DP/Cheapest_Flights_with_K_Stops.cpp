class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>mp;
    vector<vector<int>>dp;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst) return 0;
        for(auto x:flights){
            mp[x[0]].push_back({x[1],x[2]});
        }
        dp.resize(n,vector<int>(K + 2,-1));
        int ans = f(src,dst,K + 1);
        return (ans == INT_MAX ? -1 : ans);
    }
    
    int f(int i,int dst,int K){
        if(K < 0) return INT_MAX;
        if(i == dst) return 0;
        if(dp[i][K] != -1) return dp[i][K];
        int ans = INT_MAX;
        for(auto x:mp[i]){
            int val = f(x.first,dst,K - 1);
            if(f(x.first,dst,K - 1) == INT_MAX) continue;
            else ans = min(ans,x.second + val);
        }
        return dp[i][K] = ans;
    }
};
