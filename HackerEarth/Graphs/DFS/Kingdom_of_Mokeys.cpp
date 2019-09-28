// I am Varun Das from Jadavpur University
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
ll sum=0,ans=0;
bool b[nax];
vector<ll>v[nax];
ll n,m,x,y;
ll a[nax];
 
ll dfs(ll i){
    b[i]=1;
    loop(j,0,(ll) v[i].size()){
        if(b[v[i][j]] == 0){
            sum+=a[v[i][j]];
            dfs(v[i][j]);
        }
    }
    return sum;
}
 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
ll t;
cin>>t;
while(t--){
    ans=0;
    memset(b,0,sizeof(b));
    cin>>n>>m;
    loop(i,0,nax){
        v[i].clear();
    }
    loop(i,0,m){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    loop(i,1,n+1) cin>>a[i];
    loop(i,1,n+1){
        if(b[i]==0){
            sum=a[i];
            ans=max(ans,dfs(i));
            // cerr<<dfs(i)<<" ";
        }
    }
    cout<<ans<<endl;
}
 
	return 0;
}
