// I am Varun Das from Jadavpur University ---- BASIC DFS
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define mod 1000000007
#define ll long long
#define dbg(x) cerr << #x << " = " << x << endl
#define INF LLONG_MAX
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define nax 503405
using namespace std;
 
vector<ll>v[nax];
ll c[nax];
bool b[nax];
ll ans = 0;
 
ll dfs(ll i){
    b[i] = 1;
    loop(j,0,v[i].size()){
        if(!b[v[i][j]]){
            dfs(v[i][j]);
            if(c[v[i][j]] != c[i]) ++ans;
        }
    }
    return ans;
}
 
 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
ll n,p;
cin>>n;
loop(i,2,n+1){
    cin>>p;
    v[min(i,p)].push_back(max(i,p));
}
loop(i,1,n+1){
    cin>>p;
    c[i] = p;
}
memset(b,0,sizeof(b));
loop(i,1,n+1){
    if(!b[i]) dfs(i);
}
cout<<ans + 1;
	return 0;
}
