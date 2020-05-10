#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int graph[n][n];
	    for(int i = 0;i < n;i++){
	        for(int j = 0;j < n;j++){
	            cin>>graph[i][j];
	        }
	    }
	    
	    for(int k = 0;k < n;k++){
	        for(int i = 0;i < n;i++){
	            for(int j = 0;j < n;j++){
	                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
	            }
	        }
	    }
	    
	    for(int i = 0;i < n;i++){
	        for(int j = 0;j < n;j++){
	            if(graph[i][j] == 1e7) cout<<"INF"<<" ";
	            else cout<<graph[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
