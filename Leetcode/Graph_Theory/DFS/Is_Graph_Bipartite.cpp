class Solution {
public:
    unordered_map<int,bool>mp;
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans = 1;
        for(int i = 0;i < graph.size();i++){
            if(!mp.count(i)) ans &= dfs(i,graph,0);
        }
        return ans;
    }
    
    bool dfs(int i,vector<vector<int>>& graph,bool p){
        mp[i] = p;
        p = !p;
        bool ans = 1;
        for(auto j:graph[i]){
            if(mp.count(j)){
                ans &= (mp[j] == p);
            }
            else ans &= dfs(j,graph,p);
        }
        return ans;
    }
};
