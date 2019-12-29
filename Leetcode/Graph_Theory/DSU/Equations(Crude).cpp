class DSU{
    unordered_map<char,char>parent;
    unordered_map<char,int>size;
    unordered_map<char,set<char>>child;
    unordered_map<char,unordered_map<char,int>>notPossible;
    public:
        void make_set(char c){
            parent[c] = c;
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
                child[a].insert(b);
                size[a] += size[b];
            }
        }
    
        bool check(char a,char b){
            if(notPossible[a].count(b) or notPossible[b].count(a)) return 0;
            if(child[a].size() and child[b].size()) return 1;
            bool c = 1;
            for(auto x:child[a]) c &= check(x,b);
            for(auto y:child[b]) c &= check(a,y);
            return c;
        }
    
        void incompatible(char a,char b){
            notPossible[a][b] = 1;
            notPossible[b][a] = 1;
        }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;
        for(auto x:equations){
            dsu.make_set(x[0]);
            dsu.make_set(x[3]);
        }
        
        for(auto x:equations){
            if(x[1] == '='){
                if(!dsu.check(dsu.find_set(x[0]),dsu.find_set(x[3]))) return 0;
                dsu.union_set(x[0],x[3]);
            }
            else{
                if(dsu.find_set(x[0]) == dsu.find_set(x[3])) return 0;
                dsu.incompatible(dsu.find_set(x[0]),dsu.find_set(x[3]));
            }
        }
        return 1;
    }
};
