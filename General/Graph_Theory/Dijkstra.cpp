const int 1000000000;
vector<vector<pair<int,int>>>adj;

void dijkstra(int s,vector<int>& d,vector<int>& p){
  int n = adj.size();
  d.resize(n, INF);
  p.resize(n, -1);
  vector<bool>u(n, 0);
  
  d[s] = 0;
  for(int i = 0;i < n;i++){
    int v = -1;
    for(int j = 0;j < n;j++){
      if(!u[j] and (v == -1 or d[j] < d[v])) v = j;
    }
    
    if(d[v] == INF) break;
    
    u[v] = 1;
    for(auto edge : adj[v]){
      int to = edge.first;
      int len = edge.second;
      
      if(d[v] + len < d[to]){
        d[to] = d[v] + len;
        p[to] = v;
      }
    }
  }
}
