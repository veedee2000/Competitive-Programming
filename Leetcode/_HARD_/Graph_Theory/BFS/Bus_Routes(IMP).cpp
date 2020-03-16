class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T) return 0;
        int n = routes.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i < n;i++){
            for(auto stop:routes[i]) mp[stop].push_back(i);
        }
        queue<int>q;
        q.push(S);
        vector<bool>b(n,0);
        int ans = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                for(auto bus:mp[curr]){
                    if(b[bus]) continue;
                    b[bus] = 1;
                    for(auto stop:routes[bus]){
                        if(stop == T) return ans;
                        q.push(stop);
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
