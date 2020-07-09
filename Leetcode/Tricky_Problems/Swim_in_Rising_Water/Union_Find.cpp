class DSU{
    vector<int>parent, size;
    
public:
    DSU(int n){
        for(int i = 0;i < n * n;i++) parent.push_back(i), size.push_back(1);
    }
    
    int findSet(int v){
        if(v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }
    
    void unionSet(int a,int b){
        a = findSet(a), b = findSet(b);
        if(a != b){
            if(size[b] > size[a]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n);
        vector<pair<int,int>>v;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                v.push_back({grid[i][j], i * n + j});
            }
        }
        sort(v.begin(), v.end());
        vector<int>dr = {0, 0, -1, 1}, dc = {-1, 1, 0, 0};
        for(int i = 0;i < n * n;i++){
            int index = v[i].second;
            int currX = index / n, currY = index % n;
            for(int rc = 0;rc < 4;rc++){
                int x = currX + dr[rc], y = currY + dc[rc];
                if(x >= 0 and y >= 0 and x < n and y < n and grid[x][y] <= grid[currX][currY]){
                    dsu.unionSet(currX * n + currY, x * n + y);
                }
            }
            if(dsu.findSet(0) == dsu.findSet(n * n - 1)) return grid[currX][currY];
        }
        return 0;
    }
};
