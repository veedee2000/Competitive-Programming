// I am Varun Das from Jadavpur University
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define dbg(x) cerr << #x << " = " << x << endl
#define loop(i,a,b) for(int i=a;i<b;i++)
#define nax 503405
using namespace std;

ll n,k,dp[nax][26];
string s;
ll f(ll i,ll j){
    if(i <= 0) return 0;
    if(dp[i][j]!=mod) return dp[i][j];
    loop(x,0,k){
        if(x + 'A' == j + 'A') continue;
        else if(x + 'A' == s[i-1]){
            dp[i][j] = min(dp[i][j],f(i-1,x));
        }
        else{
            dp[i][j] = min(dp[i][j],f(i-1,x) + 1);
        }
    }
    return dp[i][j];
}
// ll val=0;
// vector<ll>v;
// void f1(ll i,ll j){
//     if(i < n-1){
//         ll t = ('A' + j == s[i]) ? 0 : 1;
//         if(t) ++val;
//         loop(p,0,k){
//             if(j != p and dp[i+1][k] == dp[i][j] + t){
//                 v.push_back(p);
//                 f1(i+1,p);
//                 break;
//             }
//         }
//     }
//     else{
//         ll t = ('A' + j == s[i]) ? 0 : 1;
//         if(t) ++val;
//         v.push_back(j);
//     }
// }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>n>>k;
cin>>s;
loop(i,0,nax){
    loop(j,0,26) dp[i][j] = mod;
}
cout<<f(n - 1,s[n - 1] - 'A')<<endl;
// loop(i,0,k){
//     val = 0;
//     f1(0,i);
//     cerr<<val<<" ";
//     if(val == dp[n-1][s[n-1] - 'A']) break;
//     else v.clear();
// }
// for(auto x:v){
//     cout<<char('A' + x);
// }
	return 0;
}
