#include<bits/stdc++.h>
using namespace std;

#define p pair<int,int>

bool comp(p& a, p& b){
    return a.second < b.second;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<p>activity(n);
        for(int i = 0;i < n;i++) cin >> activity[i].first;
        for(int i = 0;i < n;i++) cin >> activity[i].second;
        sort(activity.begin(), activity.end(), comp);
        int ans = 1, prevEnd = activity[0].second;
        for(int i = 1;i < n;i++){
            if(prevEnd <= activity[i].first){
                prevEnd = activity[i].second;
                ans ++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
