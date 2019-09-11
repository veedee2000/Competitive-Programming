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
ll n,b;
cin>>n>>b;
vector<ll>v;
ll a[nax],o=0,e=0,err = -1;
loop(i,0,n) cin>>a[i];
loop(i,0,n){
    if(a[i]%2 == 1){
        o++;
    }
    else e++;
    if(o == e and e){
        if(i != n-1) v.push_back(abs(a[i] - a[i+1]));
        o=0;
        e=0;
        err = 0;
    }
    else err = -1;
}
 
if(err == -1) cout<<0;
else{
    sort(v.begin(),v.end());
    ll ans=0;
    for(auto x:v){
        if(b - x >= 0){
            ans++;
            b-=x;
        }
    }
    cout<<ans;
}
 
	return 0;
}
