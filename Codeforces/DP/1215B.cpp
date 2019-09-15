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
ll n,a[nax],dp[nax][2];
ll f(ll i,ll j){
    if(i < 0) return 0;
    if(i == 0){
        if(a[i] > 0){
            dp[i][0] = 1;
        }
        else{
            dp[i][1] = 1;
        }
        return dp[i][j];
    }
    if(dp[i][j]!=0) return dp[i][j];
    if(a[i] > 0){
        dp[i][0] = f(i-1,0) + 1;
        dp[i][1] = f(i-1,1);
    }
    else{
        dp[i][0] = f(i-1,1);
        dp[i][1] = f(i-1,0) + 1;
    }
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
cin>>n;
loop(i,0,n){
    cin>>a[i];
}
memset(dp,0,sizeof(dp));
f(n-1,0);
ll p=0,ne=0;
loop(i,0,n){
    p += dp[i][0];
    ne += dp[i][1];
}
cout<<ne<<" "<<p;

	return 0;
}
