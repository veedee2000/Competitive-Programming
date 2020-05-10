#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        queue<int>q;
        q.push(0);
        vector<bool>vis(n + 1,0);
        int level = 0,ans = 0;
        while(1){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                if(curr * 2 <= n and !vis[curr * 2]){
                    q.push(curr * 2); 
                    vis[curr * 2] = 1;
                    if(curr * 2 == n) { ans = level + 1; break; }
                }
                if(curr + 1 <= n and !vis[curr + 1]){
                    q.push(curr + 1);
                    vis[curr + 1] = 1;
                    if(curr + 1 == n) { ans = level + 1; break; }
                }
            }
            if(ans) break;
            ++level;
        }
        cout<<ans<<endl;
    }
    
	return 0;
}
