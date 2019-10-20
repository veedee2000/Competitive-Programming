#include <bits/stdc++.h>
using namespace std;

int n,ans=0,v[100][100];
bool b[100][100];

void dfs(int i,int j){
	b[i][j] = 1;
	if(i == n-1 and j == n-1){
		++ans;
	}
	if(i > 0 and !b[i-1][j] and !v[i-1][j]) dfs(i-1,j), b[i-1][j] = 0;
	if(i < n-1 and !b[i+1][j] and !v[i+1][j]) dfs(i+1,j), b[i+1][j] = 0;
	if(j > 0 and !b[i][j-1] and !v[i][j-1]) dfs(i,j-1), b[i][j-1] = 0;
	if(j < n-1 and !b[i][j+1] and !v[i][j+1]) dfs(i,j+1), b[i][j+1] = 0;
	
}

int main() {
	
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>v[i][j];
			}
		}
		dfs(0,0);
		cout<<ans<<endl;
	}
	
	return 0;
}