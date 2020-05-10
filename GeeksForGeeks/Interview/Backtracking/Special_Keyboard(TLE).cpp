#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int f(int n,int copied,int total){
    if(n < 0) return -INF;
    if(n == 0) return 0;
    return max({1 + f(n - 1,copied,total + 1),copied + f(n - 1,copied,total + copied),total + f(n - 3,total,2 * total)});
}

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<f(n,0,0)<<endl;
	}
	
	return 0;
}
