// https://leetcode.com/discuss/interview-question/553399/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
	vector<int>v(n,0);
	for(int i = 0;i < n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	if(v.size() <= 4) return 0;
	cout<<min({v[n - 1] - v[3],v[n - 2] - v[2],v[n - 3] - v[1],v[n - 4] - v[0]});
	return 0;
}
