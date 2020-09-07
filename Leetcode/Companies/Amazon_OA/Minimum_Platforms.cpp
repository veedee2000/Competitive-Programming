#include<bits/stdc++.h>
using namespace std;

struct comp{
    bool operator()(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
};

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string>arrival(n), departure(n);
        for(int i = 0;i < n;i++) cin >> arrival[i];
        for(int i = 0;i < n;i++) cin >> departure[i];
        sort(arrival.begin(), arrival.end());
        sort(departure.begin(),departure.end());
        int ans = 0, i = 0, j = 0, count = 0;
        while(i < n){
            if(arrival[i] <= departure[j]) i++, count++;
            else j++, count--;
            ans = max(ans, count);
        }
        cout << ans << endl;
    }
    
    return 0;
}
