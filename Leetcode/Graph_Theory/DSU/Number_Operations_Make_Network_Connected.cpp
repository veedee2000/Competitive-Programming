class DSU{
    vector<int>parent,size;
    public:
    DSU(int n){
        for(int i = 0;i < n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void union_set(int a,int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(size[b] > size[a]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        DSU dsu(n);
        for(auto x:connections){
            dsu.union_set(x[0],x[1]);
        }
        set<int>s;
        for(int i = 0;i < n;i++){
            s.insert(dsu.find_set(i));
        }
        return s.size() - 1;
    }
};
