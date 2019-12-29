class DSU{
    unordered_map<char,char>parent;
    unordered_map<char,int>size;
    public:
        DSU(){
            string alpha = "abcdefghijklmnopqrstuvwxyz";
            for(auto x:alpha){
                parent[x] = x;
                size[x] = 1;
            }
        }
            
        char find_set(char c){
            if(c == parent[c]) return c;
            return parent[c] = find_set(parent[c]);
        }
    
        void union_set(char a,char b){
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
    bool equationsPossible(vector<string>& equations) {
        
        DSU dsu;
        for(auto x:equations){
            if(x[1] == '=') dsu.union_set(x[0],x[3]);
        }
        for(auto x:equations){
            if(x[1] == '!') if(dsu.find_set(x[0]) == dsu.find_set(x[3])) return 0;
        }
        return 1;
    }
};
