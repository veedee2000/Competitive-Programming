class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        dfs(graph,res,0,{});
        return res;
    }
    
    void dfs(vector<vector<int>> graph,vector<vector<int>>& res,int i, vector<int> path){
        path.push_back(i);
        if(i==graph.size()-1){
            res.push_back(path);
            return;
        }
        for(auto x:graph[i]){
            dfs(graph,res,x,path);
        }
    }
};
