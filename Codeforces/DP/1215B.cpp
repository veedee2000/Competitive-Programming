// I am Varun Das from Jadavpur University
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define dbg(x) cerr << #x << " = " << x << endl
#define INF LLONG_MAX
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define nax 503405
using namespace std;
ll n,a[nax],dp[200100][2],b[200100][2];
ll f(ll i,ll j){
    if(i < 0) return 0;
    if(i == 0){
        if(a[0] > 0){
            dp[0][0] = 1;
        }
        else{
            dp[0][1] = 1;
        }
        return dp[0][j];
    }
    if(b[i][j]==1) return dp[i][j];
    b[i][j] = 1;
    if(a[i] > 0){
        dp[i][0] = f(i-1,0) + 1;
        dp[i][1] = f(i-1,1);
    }
    else{
        dp[i][0] = f(i-1,1);
        dp[i][1] = f(i-1,0) + 1;
    }
    return dp[i][j];
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//cout<<fixed<<setprecision(12);
cin>>n;
loop(i,0,n){
    cin>>a[i];
    dp[i][0]=0;
    dp[i][1]=0;
    b[i][0] = 0;
    b[i][1] = 0;
}
f(n-1,0);
ll p=0,ne=0;
loop(i,0,n){
    p += dp[i][0];
    ne += dp[i][1];
}
cout<<ne<<" "<<p;

	return 0;
}
