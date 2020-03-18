/*
Input: ropes = [8, 4, 6, 12]
Output: 58
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i = 0;i < n;i++){
		cin>>v[i];
	}
	priority_queue<int,vector<int>,greater<int>>pq;
	for(auto x:v) pq.push(x);
	int ans = 0;
	while(pq.size() > 1){
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout<<ans;
	return 0;
}
