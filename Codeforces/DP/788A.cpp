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

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
ll n;
cin>>n;
ll a[nax];
loop(i,1,n+1) cin>>a[i];
ll c[nax],d[nax];
loop(i,1,n){
    if(i%2 == 0) c[i] = abs(a[i] - a[i+1]);
    else c[i] = -abs(a[i] - a[i+1]);
    // cerr<<c[i]<<" ";
}
loop(i,1,n){
    if(i%2) d[i] = abs(a[i] - a[i+1]);
    else d[i] = -abs(a[i] - a[i+1]);
    // cerr<<d[i]<<" ";
}
ll ans=0,cur=0;
loop(i,1,n){
    cur += c[i];
    if(cur <= 0){
        cur = 0;
    }
    ans = max(ans,cur);
}
cur = 0;
loop(i,1,n){
    cur += d[i];
    if(cur <= 0){
        cur = 0;
    }
    ans = max(ans,cur);
}
cout<<ans;
	return 0;
}
