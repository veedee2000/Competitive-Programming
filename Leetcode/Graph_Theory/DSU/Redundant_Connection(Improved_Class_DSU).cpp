class DSU{
    vector<int>parent,size;
    public:
    DSU(int n){
        parent.resize(n + 1),size.resize(n + 1);
        for(int i = 1;i <= n;i++) parent[i] = i, size[i] = 1;
    }
    
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void union_set(int a,int b){
        a = find_set(a),b = find_set(b);
        if(a != b){
            if(size[b] > size[b]){
                swap(a,b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n;
        for(auto x:edges) n = max({n,x[0],x[1]});
        DSU dsu(n);
        for(auto x:edges){
            if(dsu.find_set(x[0]) != dsu.find_set(x[1])) dsu.union_set(x[0],x[1]);
            else return {x[0],x[1]};
        }
        return {-1,-1};
    }
};
