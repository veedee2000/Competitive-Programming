#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int f(int i,int j){
    if(i < 0 or j < 0) return 0;
    if(i == 0 or j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = f(i - 1,j) + f(i,j - 1);
}

int main() {
    
    int t;
    cin>>t;
    while(t--){
       int m,n;
       cin>>m>>n;
       dp.clear();
       dp.resize(m,vector<int>(n,-1));
       cout<<f(m - 1,n - 1)<<endl;
    }
    
	return 0;
}
