#include <bits/stdc++.h>
using namespace std;

struct comp{ // Min-heap
	bool operator()(vector<int>& a,vector<int>& b){
		return a[0] > b[0];
	}
};

int main() {
	
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i = 0;i < n;i++) cin>>nums[i];
	
	priority_queue<vector<int>,vector<vector<int>>,comp>pq;
	
	map<int,int>mp;
	int intervalEnd = 0,intervalNumber = 1;
	for(int i = 1;i < n;i++){
		if(nums[i] < nums[i - 1]) mp[intervalNumber++] = intervalEnd;
		intervalEnd++;
	}
	mp[intervalNumber] = n - 1;
	
	pq.push({nums[0],0,mp[1]});
	for(int i = 1;i < intervalNumber;i++){
		pq.push({nums[mp[i] + 1],mp[i] + 1,mp[i + 1]});
	}
	
	vector<int>ans;
	while(!pq.empty()){
		vector<int>curr = pq.top();
		int value = curr[0],index = curr[1], lastPermittedIndex = curr[2];
		pq.pop();
		ans.push_back(value);
		if(index++ < lastPermittedIndex) pq.push({nums[index],index,lastPermittedIndex});
	}
	for(auto x:ans) cout<<x<<" ";
	
	return 0;
}
