class DSU{   
    vector<int>parent,size;

public:

    DSU(int n){
        for(int i = 0;i < n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int findSet(int s){
        if(s == parent[s]) return s;
        return parent[s] = findSet(parent[s]);
    }
    
    void unionSet(int s1,int s2){
        s1 = findSet(s1);
        s2 = findSet(s2);
        if(s1 != s2){
            if(size[s2] > size[s1]) swap(s1,s2);
            parent[s2] = s1;
            size[s1] += size[s2];
        }
    }
        
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU dsu(s.size());
        for(auto x:pairs){
            dsu.unionSet(x[0],x[1]);
        }
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i < s.size();i++) mp[dsu.findSet(i)].push_back(i);
        for(auto vec:mp){
            vector<int>pos;
            string sub;
            for(auto x:vec.second){
                pos.push_back(x);
                sub.push_back(s[x]);
            }
            sort(sub.begin(),sub.end());
            for(int i = 0;i < pos.size();i++) s[pos[i]] = sub[i];
        }
        return s;
    }
};
