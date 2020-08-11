#include<bits/stdc++.h>
using namespace std;

#define p pair<int,int>

vector<int>lt, rt;

vector<p> merge(vector<p>& l, vector<p>& r){
    vector<p>ans;
    int i = 0, j = 0, k = 0, m = l.size(), n = r.size();
    while(i < m and j < n){
        if(l[i].first < r[j].first){
            rt[l[i].second]++, lt[r[j].second]++;
            ans.push_back(l[i]);
            i++;
        }
        else{
            ans.push_back(r[j]);
            j++;
        }
        k++;
    }
    while(i < m){
        ans.push_back(l[i]);
        i++, k++;
    }
    while(j < n){
        rt[l[m - 1].second]++, lt[r[j].second]++;
        ans.push_back(r[j]);
        j++, k++;
    }
    return ans;
}

void mergeSort(vector<p>& v){
    if(v.size() <= 1) return;
    vector<p>l, r;
    int n = v.size(), m = n / 2;
    for(int i = 0;i < m;i++) l.push_back(v[i]);
    for(int i = m;i < n;i++) r.push_back(v[i]);
    mergeSort(l);
    mergeSort(r);
    v = merge(l, r);
}

int main(){
    
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    lt.resize(n, 0), rt.resize(n, 0);
    vector<p>v;
    for(int i = 0;i < n;i++){
        cin >> nums[i];
        v.push_back({nums[i], i});
    }
    mergeSort(v);
    
    int ans = 0;
    for(int i = 0;i < n;i++) ans += lt[i] * rt[i];
    // for(int i = 0;i < n;i++) cout << lt[i] << " " << rt[i] << endl;
    cout << ans;
    
    return 0;
}
