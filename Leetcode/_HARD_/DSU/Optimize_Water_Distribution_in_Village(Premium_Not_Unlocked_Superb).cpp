// https://github.com/azl397985856/leetcode/blob/master/problems/1168.optimize-water-distribution-in-a-village-en.md

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>well;
vector<vector<int>>pipes;

class DSU{
	vector<int>parent,size;
	public:
		DSU(int n){
			for(int i = 0;i <= n;i++){
				parent.push_back(i);
				size.push_back(1);
			}
		}
		
		int findSet(int v){
			if(v == parent[v]) return v;
			return parent[v] = findSet(parent[v]);
		}
		
		void unionSet(int a,int b){
			a = findSet(a);
			b = findSet(b);
			
			if(a != b){
				if(size[b] > size[a]) swap(a,b);
				parent[b] = a;
				size[a] += size[b];
			}
		}
};

bool comp(vector<int>a,vector<int>b){
	return a[2] < b[2];
}

int solve(){
	DSU dsu(n);
	for(int i = 1;i <= n;i++) pipes.push_back({0,i,well[i]});
	sort(pipes.begin(),pipes.end(),comp);
	int totalConnections = 0,ans = 0;
	for(auto x:pipes){
		int house1 = x[0],house2 = x[1],pipeCost = x[2];
		if(dsu.findSet(house1) != dsu.findSet(house2)){
			dsu.unionSet(house1,house2);
			ans += pipeCost;
			totalConnections++;
			if(totalConnections == n) break;
		}
	}
	return ans;
}

int main() {
	
	cin>>n;
	well.resize(n + 1);
	for(int i = 1;i <= n;i++) cin>>well[i];
	
	cin>>m;
	pipes.resize(m,vector<int>(3));
	for(int i = 0;i < m;i++) cin>>pipes[i][0]>>pipes[i][1]>>pipes[i][2];
	
	cout<<solve();
	
	return 0;
}
