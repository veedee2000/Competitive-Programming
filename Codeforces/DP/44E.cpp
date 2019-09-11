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
 
ll k,a,b,dp[2000][2000],n;
bool c = 0;
string s;
vector<ll>ans,v;
ll f(ll i,ll j){
    if(c == 1) return 0;
    if(i == n and j == 0){
        ans = v;
        c=1;
        return 0;
    }
    if(i > n) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    loop(p,a,b+1){
        v.push_back(p);
        f(i+p,j-1);
        v.pop_back();
    }
    dp[i][j] = 1;
}
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
cin>>k>>a>>b;
cin>>s;
n = s.size();
memset(dp,-1,sizeof(dp));
f(0,k);
for(auto x:ans) cerr<<x<<" ";
if(ans.size() == 0) cout<<"No solution";
else{
    int i=0,lo=0;
    for(auto x:ans){
        lo+=x;
        while(i < lo){
            cout<<s[i];
            i++;
        }
        cout<<endl;
    }
}
 
	return 0;
}
