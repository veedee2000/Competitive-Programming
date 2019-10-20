#include <bits/stdc++.h>
using namespace std;

vector<int>v[1000];
bool visited[1000];

void dfs(int i){
	visited[i] = 1;
	for(int i=0;i<v[i].size();i++){
		if(!b[v[i][j]]) dfs(v[i][j]);
	}
}

int main() {
	
	int n,m,x,y;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y) // Considering Directed Graph.
	}
	memset(visited,0,sizeof(visited));
	
	for(int i=1;i<m+1;i++){
		dfs(i);
	}
	
	return 0;
}
