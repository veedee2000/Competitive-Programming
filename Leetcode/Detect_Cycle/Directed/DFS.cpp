bool dfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
    if(vis[i]) return 1;
    vis[i] = 1;
    for(auto next:adj[i]){
        if(dfs(next, adj, vis)) return 1;
    }
    vis[i] = 0;
    return 0;
}

int Solution::solve(int V, vector<vector<int> > &edgeList) {
    vector<vector<int>>adj(V + 1);
    for(auto edge:edgeList){
        adj[edge[0]].push_back(edge[1]);
    }
    vector<bool>vis(V + 1);
    for(int i = 1;i <= V;i++){
        if(!vis[i] and dfs(i, adj, vis)) return 1;
    }
    return 0;
}
