class Solution {
public:
    vector<int>v,b;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        b.resize(graph.size(),0);
        for(int i = 0;i < graph.size();i++){
            if(!graph[i].size()) v.push_back(i);
            else dfs(i,graph);
        }
        sort(v.begin(),v.end());
        return v;
    }
    
    bool dfs(int i,vector<vector<int>>& graph){
        if(graph[i].size() == 0) return true;
        if(b[i] == 2) return false; // This state is currently in process(Loop formation)
        if(b[i] == 1) return true; // This state results true
        if(b[i] == -1) return false; // This state results false
        b[i] = 2;
        bool ans = 1;
        for(int j = 0;j < graph[i].size();j++){
            ans &= dfs(graph[i][j],graph);
        }
        if(ans) v.push_back(i),b[i] = 1;
        else b[i] = -1;
        return ans;
    }
};
