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

ll n,m;
vector<ll>v[1000];
bool b[nax];
void dfs(ll i){
    b[i] = 1;
    loop(j,0,v[i].size()){
        if(!b[v[i][j]]) dfs(v[i][j]);
    }
}


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
cin>>n>>m;
char c;
loop(i,1,n+1){
    cin>>c;
    if(c == '>'){
        loop(j,1,m){
            v[m * (i - 1) + j].push_back(m * (i - 1) + j + 1);
        }
    }
    else{
        rep(j,m-1,1){
            v[m * (i - 1) + j + 1].push_back(m * (i - 1) + j);
        }
    }
}
loop(i,1,m+1){
    cin>>c;
    if(c == 'v'){
        loop(j,1,n){
            v[m * (j - 1) + i].push_back(m * (j) + i);
        }
    }
    else{
        rep(j,n-1,1){
            v[m * (j) + i].push_back(m * (j - 1) + i);
        }
    }
}

loop(i,1,n+1){
    loop(j,1,m+1){
        memset(b,0,sizeof(b));
        dfs(m * (i - 1) + j);
        loop(i1,1,n+1){
            loop(j1,1,m+1){
                if(!b[m * (i1 - 1) + j1]) {cout<<"NO"; return 0;}
            }
        }
    }
}
cout<<"YES";
	return 0;
}
