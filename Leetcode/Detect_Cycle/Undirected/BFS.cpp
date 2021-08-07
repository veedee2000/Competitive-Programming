bool bfs(int V, vector<vector<int>>& adj){
    vector<bool>vis(V + 1, 0);
    queue<pair<int, int>>q;
    for(int i = 1;i <= V;i++){
        if(!vis[i]) q.push({i, 0});
        while(!q.empty()){
            auto [curr, pre] = q.front();
            q.pop();
            if(vis[curr]) return 1;
            vis[curr] = 1;
            for(auto next:adj[curr]){
                if(next != pre){
                    q.push({next, curr});
                }
            }
        }
    }
    return 0;
}

int Solution::solve(int V, vector<vector<int>> &edgeList) {
    vector<vector<int>>adj(V + 1);
    for(auto edge:edgeList){
        adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);
    }
    return bfs(V, adj);
}
