bool dfs(int i, int pre, vector<vector<int>>& adj, int V, vector<bool>& vis){
    if(vis[i]) return 1;
    vis[i] = 1;
    for(auto next:adj[i]){
        if(next != pre and dfs(next, i, adj, V, vis)) return 1;
    }
    return 0;
}

int Solution::solve(int V, vector<vector<int>> &edgeList) {
    vector<bool>vis(V + 1, 0);
    vector<vector<int>>adj(V + 1);
    for(auto edge:edgeList){
        adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);
    }
    for(int i = 0;i < V;i++){
        if(!vis[i] and dfs(i, 0, adj, V, vis)) return 1;
    }
    return 0;
}
