class Solution {
public:
    vector<int>parent,size,ans;
    bool check;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size() + 1);
        size.resize(edges.size() + 1);
        int n = edges.size();
        check = 0;
        for(int i = 1;i <= n;i++) make_set(i);
        for(int i = 0;i < edges.size();i++){
            union_set(edges[i][0],edges[i][1]);
            if(check) break;
        }
        return ans;
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
        int root_a = find_set(a);
        int root_b = find_set(b);
        if(root_a != root_b){
            if(size[root_a] < size[root_b]){
                swap(root_a,root_b);
            }
            parent[root_b] = root_a;
            size[a] += size[b];
        }
        else{
            check = 1;
            ans.push_back(min(a,b));
            ans.push_back(max(a,b));
        }
    }
};
