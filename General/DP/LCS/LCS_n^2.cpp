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

ll dp[2010][2010],n,m;
string s1,s2;
ll f(ll i, ll j){
    if(i < 0 or j < 0) return 0;
    if(dp[i][j]!=0) return dp[i][j];
    if(s1[i] == s2[j]){
        if(i == 0 or j == 0) dp[i][j] = 1;
        else dp[i][j] = f(i-1,j-1) + 1;
    }
    else dp[i][j] = max(f(i,j-1),f(i-1,j));
    return dp[i][j];
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
cin>>s1>>s2;
n = s1.length();
m = s2.length();
loop(i,0,2000){
    loop(j,0,2000) dp[i][j] = 0;
}
cout<<f(n-1,m-1);

	return 0;
}
