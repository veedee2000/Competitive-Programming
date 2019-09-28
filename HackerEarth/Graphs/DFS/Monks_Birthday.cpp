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
vector<ll>graph[nax];
ll v,e,val=0,ans=INF;
bool b[nax];
ll dfs(ll i){
    b[i]=1;
    loop(j,0,graph[i].size()){
        if(!b[graph[i][j]]){
            dfs(graph[i][j]);
        }
    }
    return ++val;
}
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
cin>>v>>e;
ll x,y;
loop(i,0,e){
    cin>>x>>y;
    graph[x].push_back(y);
}
memset(b,0,sizeof(b));
loop(i,1,v+1){
    // if(!b[i]){
        val=0;
        memset(b,0,sizeof(b));
        dfs(i);
        ans=min(ans,val);
    // }
}
cout<<ans<<endl;
 
 
	return 0;
}
