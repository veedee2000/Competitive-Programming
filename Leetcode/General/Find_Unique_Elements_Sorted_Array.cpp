// https://leetcode.com/discuss/interview-question/629432/facebook-phone-unique-elements-in-a-sorted-array-clone-graph

/*
  Count the unique elements in an Sorted Array.
  
  Input: [1, 1, 1, 1, 2, 2, 2, 2, 5, 5, 5, 7, 7, 8, 8, 10]
  Output = 6 
*/

#include <bits/stdc++.h>
using namespace std;

int binSearch(int i,vector<int>& a){
    int l = i,r = a.size() - 1,m,ans;
    while(l <= r){
        m = l + (r - l) / 2;
        if(a[i] == a[m]) ans = m, l = m + 1;
        else r = m - 1;
    }
    return ans;
}

int main() {
    
    int n,ans = 0;
    cin>>n;
    vector<int>a(n,0);
    for(int i = 0;i < n;i++) cin>>a[i];
    for(int start = 0;start < n;){
        int end = binSearch(start,a);
        start = end + 1;
        ans++;
    }
    
    cout<<ans;
    
	return 0;
}
