#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int>dp;

int f(int i,vector<int>& v){
    if(i == v.size() - 1) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INF;
    for(int j = 1;j <= v[i] and i + j < v.size();j++){
        ans = min(ans,1 + f(i + j,v));
    }
    return dp[i] = ans;
}

int main() {
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i = 0;i < n;i++) cin>>v[i];
        dp.clear();
        dp.resize(n,-1);
        int ans = f(0,v);
        if(ans == INF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    
	return 0;
}
