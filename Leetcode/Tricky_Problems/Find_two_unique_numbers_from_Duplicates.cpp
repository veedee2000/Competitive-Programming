// https://practice.geeksforgeeks.org/problems/finding-the-numbers/0

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n = 2 * n + 2;
        vector<int>a(n,0);
        int XOR = 0;
        for(int i = 0;i < n;i++) cin>>a[i], XOR ^= a[i];
        int MSB;
        for(int i = 31;i >= 0;i--){
            if( (1 << i) & XOR ) { MSB = i; break; }
        }
        int x = 0, y = 0;
        for(auto num:a){
            if( (1 << MSB) & num) x ^= num;
            else y ^= num;
        }
        cout<<min(x,y)<<" "<<max(x,y)<<endl;
    }
	return 0;
}
