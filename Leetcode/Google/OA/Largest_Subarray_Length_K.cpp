// https://leetcode.com/discuss/interview-question/352459/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i = 0;i < n;i++) cin>>v[i];
    int k;
    cin>>k;
    int maxVec = 0;
    for(int i = 1;i <= n - k;i++){
        for(int j = 0;j < k;j++){
            if(v[maxVec + j] != v[i + j]){
                maxVec = (v[maxVec + j] > v[i + j]) ? maxVec : i;
                break;
            }
        }
    }
    vector<int>ans(v.begin() + maxVec,v.begin() + maxVec + k);
    for(auto x:ans) cout<<x<<" ";
	return 0;
}
