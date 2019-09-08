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
ll n,k;
ll m = 2*100000 + 100;
cin>>n>>k;
ll a[nax];
vector<ll>v,b(m),v1;
loop(i,0,n){
    cin>>a[i];
    b[a[i]]++;
}
ll l = 0,r = 2*100000 + 100,mid,ans=0;
while(l <= r){
    mid = l + (r-l)/2;
    if(l == r - 1){
        v.clear();
        loop(i,0,m){
            ll need = min(b[i]/l,k - (ll) v.size());
            loop(j,0,need) v.push_back(i);
        }
        if((ll) v.size() == k) v1 = v;
        v.clear();
        loop(i,0,m){
            ll need = min(b[i]/r,k - (ll) v.size());
            loop(j,0,need) v.push_back(i);
        }
        if((ll) v.size() == k) v1 = v;
        for(auto x:v1) cout<<x<<" ";
        return 0;
    }
    v.clear();
    loop(i,0,m){
        ll need = min(b[i]/mid,k - (ll) v.size());
        loop(j,0,need) v.push_back(i);
    }
    if((ll) v.size() == k){
        v1 = v;
        l = mid;
    }
    else{
        r = mid;
    }
}
for(auto x:v1) cout<<x<<" ";

	return 0;
}
