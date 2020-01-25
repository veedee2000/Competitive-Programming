// William Fisets Graph Theory : Number of Bridges

class Solution {
public:
    int n,id;
    vector<vector<int>>graph,ans;
    vector<int>low,ids;
    vector<bool>visited;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        this -> n = n;
        graph.resize(n);
        low.resize(n);
        ids.resize(n);
        visited.resize(n,0);
        id = 0;
        
        for(auto x:connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        for(int i = 0;i < n;i++) if(!visited[i]) dfs(i,-1);
            
        return ans;
    }
    
    void dfs(int at,int parent){
        visited[at] = 1;
        low[at] = ids[at] = ++id;
        
        for(auto to:graph[at]){
            if(to == parent) continue;
            if(!visited[to]){
                dfs(to,at);
                low[at] = min(low[at],low[to]);
                if(ids[at] < low[to]){
                    ans.push_back({at,to});
                }
            }
            else{
                low[at] = min(low[at],ids[to]);
            }
        }
    }
};
