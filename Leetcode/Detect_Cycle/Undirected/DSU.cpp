class DSU{
    vector<int>parent, size;
    
public:
    
    DSU(int n){
        for(int i = 0;i <= n;i++) parent.push_back(i), size.push_back(1);
    }
    
    bool isSameSet(int a, int b){
        return findSet(a) == findSet(b);
    }
    
    int findSet(int v){
        if(v == parent[v]) return v;
        return parent[v] = findSet(parent[v]); 
    }
    
    void unionSet(int a, int b){
        a = findSet(a), b = findSet(b);
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
    
};

class Solution {
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(auto edge:edges){
            if(dsu.isSameSet(edge[0], edge[1])) return edge;
            dsu.unionSet(edge[0], edge[1]);
        }
        return {};
    }
};
