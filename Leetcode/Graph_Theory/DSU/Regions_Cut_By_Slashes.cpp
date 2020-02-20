class DSU{
    vector<int>parent,size;
    public:
    DSU(int n){
        for(int i = 0;i < n;i++) parent.push_back(i),size.push_back(1);
    }
    
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void union_set(int a,int b){
        a = find_set(a),b = find_set(b);
        if(a != b){
            if(size[b] > size[a]) swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
};


class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size() + 1;
        int ans = 1;
        DSU* dsu = new DSU(n * n);
        for(int i = 0;i < n - 1;i++){
            dsu -> union_set(i,i + 1);
            dsu -> union_set(n * (n - 1) + i,n * (n - 1) + i + 1);
            dsu -> union_set(i * n,(i + 1) * n);
            dsu -> union_set(n - 1 + i * n,n - 1 + (i + 1) * n);
        }
        for(int i = 0;i < grid.size();i++){
            int j = 0;
            for(auto x:grid[i]){
                if(x == '/'){
                    if(dsu -> find_set(i * n + j + 1) != dsu -> find_set((i + 1) * n + j)) dsu -> union_set(i * n + j + 1,(i + 1) * n + j);
                    else ans++;
                }
                else if(x == '\\'){
                   if(dsu -> find_set(i * n + j) != dsu -> find_set((i + 1) * n + j + 1)) dsu -> union_set(i * n + j,(i + 1) * n + j + 1);
                    else ans++;
                }
                j++;
            }
        }
        return ans;
    }
};
