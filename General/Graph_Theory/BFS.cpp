#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>v[1000];
bool visited[1000];
int level[1000];

void bfs(int i){
	queue<int>q;
	level[i] = 0;
	visited[i] = 1;
	
	while(!q.empty()){
		int current  = q.front();
		q.pop();
		for(int j=0;j<v[current].size();j++){
			if(!visited[v[current][j]]){
				level[v[current][j]] = level[current] + 1;
				q.push(v[current][j]);
				visited[v[current][j]] = 1;
			}
		}
	}
}

int main() {
	
	int n,m,x,y;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y); // Considering Directed Graph.
	}
	memset(visited,0,sizeof(visited));
	for(int i=1;i<m+1;i++){
		bfs(i);
	}
	
	return 0;
}