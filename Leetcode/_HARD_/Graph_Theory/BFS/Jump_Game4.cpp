class Solution {
    
    // Cannot be solved by dp as there can be cyclic dependancy on a given state. Solve with BFS.
    
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i < n;i++) mp[arr[i]].push_back(i);
        queue<int>q;
        q.push(0);
        vector<int>b(n,0);
        b[0] = 1;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                if(curr == n - 1) return ans;
                if(curr > 0 and !b[curr - 1]){
                    b[curr - 1] = 1;
                    q.push(curr - 1);
                }
                if(curr < n - 1 and !b[curr + 1]){
                    b[curr + 1] = 1;
                    q.push(curr + 1);
                }
                for(auto x:mp[arr[curr]]){
                    if(!b[x]){
                        b[x] = 1;
                        q.push(x);
                    }
                    mp[arr[curr]] = {};
                }
            }
            ans++;
        }
        return -1;
    }
};
