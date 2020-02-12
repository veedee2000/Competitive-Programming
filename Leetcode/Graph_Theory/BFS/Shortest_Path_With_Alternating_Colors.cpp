class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        unordered_map<int,vector<int>>red,blue;
        for(auto x:red_edges) red[x[0]].push_back(x[1]);
        for(auto x:blue_edges) blue[x[0]].push_back(x[1]);
        queue<vector<int>>q;
        q.push({0,0,0});
        q.push({0,0,1});
        
        vector<bool>br(n,0),bb(n,0);
        vector<int>ans(n,-1);
        while(!q.empty()){
            vector<int>curr = q.front();
            int node = curr[0],distance = curr[1],color = curr[2];
            q.pop();
            
            (color == 0 ? br[node] : bb[node]) = 1;
            if(ans[node] == -1) ans[node] = distance;
            else ans[node] = min(ans[node],distance);
            
            for(auto x:(color == 0 ? red[node] : blue[node])){
                if(color == 0 ? !bb[x] : !br[x]){
                    q.push({x,distance + 1,!color});
                }
            }
            
        }
        return ans;
    }
};
