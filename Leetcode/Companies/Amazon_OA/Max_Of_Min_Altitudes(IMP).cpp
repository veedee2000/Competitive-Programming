// https://leetcode.com/discuss/interview-question/383669/
#include<bits/stdc++.h>
using namespace std;

int MAX_VALUE = 1000000001;
vector<vector<int>>dp;

int f(int i,int j,vector<vector<int>>& grid){
	if(i == grid.size() - 1 and j == grid[0].size() - 1) return MAX_VALUE;
	if(i >= grid.size() or j >= grid[0].size()) return INT_MAX;
	if(dp[i][j] != INT_MAX) return dp[i][j];
	
	int down = f(i + 1,j,grid),downval;
	int right = f(i,j + 1,grid),rightval;
	
	if(down == INT_MAX) downval = INT_MIN;
	else downval = min(grid[i][j],down);
	
	if(right == INT_MAX) rightval = INT_MIN;
	else rightval = min(grid[i][j],right);
	
	return dp[i][j] = max(downval, rightval);
} 

int maxOfMinAltitudes(vector<vector<int>>& grid){
	int n = grid.size(),m = grid[0].size();
	grid[0][0] = MAX_VALUE;
	dp.resize(n,vector<int>(m,INT_MAX));
	return f(0,0,grid);
}

int main(){
	int n = 3,m = 3;
	vector<vector<int>>grid(n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			int x;
			cin>>x;
			grid[i].push_back(x);
		}
	}
	cout<<maxOfMinAltitudes(grid);
	return 0;
}
