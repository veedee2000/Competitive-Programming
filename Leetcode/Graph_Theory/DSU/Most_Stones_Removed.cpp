class Solution {
public:
    vector<int>parent,size;
    vector<vector<int>>stones;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int component = n;
        parent.resize(n);
        size.resize(n);
        this -> stones = stones;
        
        for(int i = 0;i < n;i++) make_set(i);
        
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]){
                    if(find_set(i) != find_set(j)){
                        union_set(i,j);
                        --component;
                    }
                }
            }
        }
        
        return n - component;
    }

    void make_set(int v){
        parent[v] = v;
        size[v] = 1;
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
