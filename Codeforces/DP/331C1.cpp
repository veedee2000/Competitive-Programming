// I am Varun Das from Jadavpur University
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define mod 1000000007
#define ll long long
#define dbg(x) cerr << #x << " = " << x << endl
#define INF LLONG_MAX
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define nax 503405
using namespace std;
 
int n,dp[1000100];
string p[1000100];
int f(int i){
    if(i == 0) return 0;
    if(i < 0) return mod;
    if(dp[i]!=mod) return dp[i];
    p[i] = to_string(i);
    loop(j,0,p[i].size()){
        dp[i] = min(dp[i],f(i - (p[i][j] - '0')) + 1);
    }
    return dp[i];
}
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
cin>>n;
loop(i,0,n+20) dp[i] = mod;
cout<<f(n);
 
	return 0;
}
