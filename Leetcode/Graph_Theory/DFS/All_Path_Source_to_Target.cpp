class Solution {
public:
    int count = 0;
    vector<vector<int>>graph,ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this -> graph = graph;
        ans.resize(100100,vector<int>(0));
        vector<int>aux;
        aux.push_back(0);
        dfs(0,aux);
        ans.resize(count,vector<int>(0));
        return ans;
    }
    
    void dfs(int i,vector<int>aux){
        for(int j = 0;j < graph[i].size();j++){
            aux.push_back(graph[i][j]);
            if(graph[i][j] == graph.size() - 1) {
                for(auto x:aux) ans[count].push_back(x);
                ++count;
            }
            else dfs(graph[i][j],aux);
            aux.pop_back();
        }
    }
};
