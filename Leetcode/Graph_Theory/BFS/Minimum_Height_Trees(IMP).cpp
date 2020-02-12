class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return {0};
        
        vector<vector<int>>edge(n);
        vector<int>inEdge(n,0),ans;
        for(auto x:edges){
            edge[x[0]].push_back(x[1]);
            edge[x[1]].push_back(x[0]);
            inEdge[x[0]]++,inEdge[x[1]]++;
        }
        queue<int>leaves;
        for(int i = 0;i < edge.size();i++){
            if(edge[i].size() == 1) leaves.push(i);
        }
        while(!leaves.empty()){
            int size = leaves.size();
            for(int i = 0;i < size;i++){
                int curr = leaves.front();
                leaves.pop();
                if(n <= 2) ans.push_back(curr);
                for(auto x:edge[curr]){
                    inEdge[x]--;
                    if(inEdge[x] == 1) leaves.push(x);
                }
            }
            n -= size;
        }
        return ans;
    }
};
