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
            if(size[a] < size[b]){
                swap(a,b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>>v;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                v.push_back({grid[i][j],i * n + j});
            }
        }
        sort(v.begin(),v.end());
        vector<int>dr = {-1,1,0,0},dc = {0,0,-1,1};
        int ans = 0;
        DSU dsu(n * n);
        for(auto x:v){
            int i = x.second / n;
            int j = x.second % n;
            for(int rc = 0;rc < 4;rc++){
                int x = i + dr[rc];
                int y = j + dc[rc];
                if(x >=0 and y >= 0 and x < n and y < n and grid[x][y] <= grid[i][j]){
                    dsu.union_set(i * n + j,x * n + y);
                }
            }
            if(dsu.find_set(0) == dsu.find_set(n * n - 1)) return grid[i][j];
        }
        return n * n - 1;
    }
};
