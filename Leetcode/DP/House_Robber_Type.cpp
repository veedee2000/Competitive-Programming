#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int f(int i,bool b,vector<int>& a){
    if(i == a.size()) return 0;
    if(dp[i][b] != -1) return dp[i][b];
    if(!b) dp[i][b] = min(a[i] + f(i + 1,0,a),f(i + 1,1,a));
    if(b) dp[i][b] = a[i] + f(i + 1,0,a);
    return dp[i][b];
}

int main() {
    
    int n;
    cin>>n;
    
    vector<int>a(n,0);
    for(int i = 0;i < n;i++) cin>>a[i];
    
    dp.resize(n,vector<int>(2,-1));
    cout<<f(0,0,a);
    
	return 0;
}
