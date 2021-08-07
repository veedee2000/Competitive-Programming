bool bfs(int V, vector<vector<int>>& adj){
    vector<int>indegree(V + 1);
    for(int i = 1;i <= V;i++) for(auto node:adj[i]) indegree[node]++;
    queue<int>q;
    for(int i = 1;i <= V;i++) if(indegree[i] == 0) q.push(i);
    int count = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        count++;
        for(auto node:adj[curr]){
            if(--indegree[node] == 0) q.push(node);
        }
    }
    return count < V;
}

int Solution::solve(int V, vector<vector<int> > &edgeList) {
    vector<vector<int>>adj(V + 1);
    for(auto edge:edgeList){
        adj[edge[0]].push_back(edge[1]);
    }
    return bfs(V, adj);
}
