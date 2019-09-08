// I am Varun Das from Jadavpur University
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define mod 1000000007
#define ll unsigned long long
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
ll n,k;
cin>>n>>k;
ll a[nax],b[nax],d[nax],c[nax];
loop(i,0,n) cin>>a[i];
loop(i,0,n) cin>>b[i],c[i] = b[i]/a[i],d[i] = b[i]%a[i];
ll l=0,r=2 * mod,mid;
ll ans=0;
while(l <= r){
    mid = l + (r - l)/2;
    // cerr<<l<<" "<<mid<<" "<<r<<endl;
    ll p = 0;
    loop(i,0,n){
        if(c[i] < mid){
            p += (a[i] - d[i]);
            p += (ll) ((mid - c[i] - 1)*a[i]);
        }
    }
    if(l == r-1){
        p = 0;
        loop(i,0,n){
            if(c[i] < l){
                p += (a[i] - d[i]);
                p += (ll) ((l - c[i] - 1)*a[i]); 
            }
        }
        if(p <= k) ans = max(l,ans);
        p = 0;
        loop(i,0,n){
            if(c[i] < r){
                p += (a[i] - d[i]);
                p += (ll) ((r - c[i] - 1)*a[i]); 
            }
        }
        if(p <= k) ans = max(r,ans);
        cout<<ans;
        return 0;
    }
    else if(p > k){
        r = mid;
    }
    else{
        l = mid;
        ans = max(ans,mid);
    }
    // cerr<<p<<endl;
}
cout<<ans;


	return 0;
}
