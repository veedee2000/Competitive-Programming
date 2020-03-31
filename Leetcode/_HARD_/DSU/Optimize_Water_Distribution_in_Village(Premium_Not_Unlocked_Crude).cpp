#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>well;
vector<vector<int>>pipes;

class DSU{
	vector<int>parent,size;
	public:
		DSU(int n){
			for(int i = 0;i < n;i++){
				parent.push_back(-1);
				size.push_back(0);
			}
		}
		
		void setParentInitial(int i){
			parent[i] = i;
			size[i] = 1;
		}
		
		int findSet(int v){
			if(parent[v] == -1) return -1;
			if(v == parent[v]) return v;
			return parent[v] = findSet(parent[v]);
		}
		
		void unionSet(int a,int b){
			if(findSet(a) == -1){
				setParentInitial(a);
			}
			else a = findSet(a);
			
			if(findSet(b) == -1){
				setParentInitial(b);
			}
			else b = findSet(b);
			
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
	sort(pipes.begin(),pipes.end(),comp);
	int ans = 0;
	for(auto x:pipes){
		int house1 = x[0],house2 = x[1],costPipe = x[2];
		if(dsu.findSet(house1) == -1 and dsu.findSet(house2) == -1){
			if(costPipe + well[house1] < costPipe + well[house2]){
				if(costPipe + well[house1] < well[house1] + well[house2]){
					
					dsu.setParentInitial(house1);
					dsu.unionSet(house1,house2);
					ans += costPipe + well[house1];
				}
				else{
					
					dsu.setParentInitial(house1);
					dsu.setParentInitial(house2);
					ans += well[house1] + well[house2];
				}
			}
			else{
				if(costPipe + well[house1] < well[house1] + well[house2]){
					dsu.setParentInitial(house2);
					dsu.unionSet(house1,house2);
					ans += costPipe + well[house2];
				}
				else{
					dsu.setParentInitial(house1);
					dsu.setParentInitial(house2);
					ans += well[house1] + well[house2];
				}
			}
		}
		else if(dsu.findSet(house1) == -1){
			if(well[house1] < costPipe){
				
				dsu.setParentInitial(house1);
				ans += well[house1];
			}
			else{
				
				dsu.unionSet(house1,house2);
				ans += costPipe;
			}
		}
		else if(dsu.findSet(house2) == -1){
			if(well[house2] < costPipe){
				
				dsu.setParentInitial(house2);
				ans += well[house2];
			}
			else{
				
				dsu.unionSet(house1,house2);
				ans += costPipe;
			}
		}
	}
	for(int i = 0;i < n;i++) if(dsu.findSet(i) == -1) ans += well[i];
	return ans;
}

int main() {
	
	cin>>n;
	well.resize(n);
	for(int i = 0;i < n;i++) cin>>well[i];
	
	cin>>m;
	pipes.resize(m,vector<int>(3));
	for(int i = 0;i < m;i++) cin>>pipes[i][0]>>pipes[i][1]>>pipes[i][2];
	
	cout<<solve();
	
	return 0;
}
