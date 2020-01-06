class Solution {
public:
    vector<bool>b;
    vector<int>v;
    unordered_map<int,int>mp;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        b.resize(graph.size(),0);
        for(int i = 0;i < graph.size();i++){
            if(!graph[i].size()) v.push_back(i),mp[i]++;
            else dfs(i,graph);
        }
        sort(v.begin(),v.end());
        return v;
    }
    
    bool dfs(int i,vector<vector<int>>& graph){
        if(graph[i].size() == 0) return true;
        if(mp.count(i)) return true;
        if(b[i]) return false;
        b[i] = 1;
        bool ans = 1;
        for(int j = 0;j < graph[i].size();j++){
            ans &= dfs(graph[i][j],graph);
        }
        if(ans) v.push_back(i),mp[i]++;
        return ans;
    }
};
