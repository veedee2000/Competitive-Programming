// https://leetcode.com/discuss/interview-question/602944/de-shaw-online-coding-test  
// Q.2 

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<vector<int>>dp;

int f(int n,int k){
    if(n < k) return 0;
    if(n == k) return 1;
    if(k == 1) return 1;
    if(dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = ( (k * f(n - 1,k)) % mod + (f(n - 1,k - 1)) % mod ) % mod;
}

int main() {
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	dp.resize(n + 1,vector<int>(n + 1,-1));
    	long ans = 0,fac = 1;
    	for(int k = 1;k <= n;k++){
    	    fac *= k;
    	    ans = (ans + (fac * f(n,k)) % mod) % mod;
    	}
    	cout<<ans<<endl;
    }
	return 0;
}
