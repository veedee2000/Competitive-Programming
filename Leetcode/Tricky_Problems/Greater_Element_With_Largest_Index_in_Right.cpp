https://leetcode.com/discuss/interview-question/688722/bloomberg-phone

/*
Input a = [21,5,6,56,88,52], output = [5,5,5,4,-1,-1] . 
Output array values is made up of indices of the element with value greater than the current element but with largest index.
So 21 < 56 (index 3), 21 < 88 (index 4) but also 21 < 52 (index 5) so we choose index 5 (value 52). Same applies for 5,6 and for 56 its 88 (index 4).
If there is no greater element then use -1 and last element of the array will always have value of -1 in output array since there is no other elment after it. 
Follow up to consider the input as a stream, how can we only update smaller element (use specific Data structure), 
running time and space complexity discussion.
*/

// Binary Search 


#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<vector<int>>& sorted, int target){
    int l = 0, r = sorted.size() - 1, ans = sorted.size(), m;
    while(l <= r){
        m = l + (r - l) / 2;
        if(sorted[m][0] <= target) l = m + 1;
        else r = m - 1, ans = m;
    }
    return ans;
}

int main() {
    
    vector<int> arr = {21,5,6,56,88,52};
    
    vector<int> ans(arr.size(), -1);
    
    vector<vector<int>> sorted;
    int lb, n = arr.size();
    
    for(int i = n - 1;i >= 0;i--){
        lb = lowerBound(sorted,arr[i]);
        if(lb != sorted.size()){
            ans[i] = sorted[lb][1];
        }
        if(i == n - 1 or sorted[sorted.size() - 1][0] < arr[i]) sorted.push_back({arr[i], i});
    }
    
    for(auto x:ans) cout << x << " ";
    
	return 0;
}

// Priority Queue

#include <bits/stdc++.h>
using namespace std;

struct comp{
    bool operator ()(vector<int>& a,vector<int>& b){
        return a[0] < b[0];
    }
};

int main() {
    
    vector<int> arr = {21,5,6,56,88,52};
    
    vector<int> ans(arr.size(), -1);
    
    priority_queue<vector<int>,vector<vector<int>>,comp>pq;
    for(int i = 0;i < arr.size();i++) pq.push({arr[i], i});
    
    int maxIndex = -1;
    
    while(!pq.empty()){
        vector<int>curr = pq.top();
        pq.pop();
        
        if(maxIndex == -1) maxIndex = curr[1];
        else{
            if(maxIndex > curr[1]) ans[curr[1]] = maxIndex;
            else maxIndex = curr[1];
        }
    }
    
    for(auto x:ans) cout << x << " "; 
    
	return 0;
}
