class DSU{
    
    vector<int>parent, size;
public:
    
    DSU(int n){
        for(int i = 0;i < n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
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
    
    int retSize(int v){
        return size[v];
    }
    
};

class Solution {
    
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size(), ans = 1;
        unordered_map<int,int>mp;
        
        DSU dsu(n);
        int num;
        
        for(int i = 0;i < A.size();i++){
            int num = A[i];
            while(num > 1){
                while(num % 2 == 0){
                    num /= 2;
                    if(mp.count(2) and mp[2] != i){
                        dsu.unionSet(mp[2], i);
                    }
                    mp[2] = i;
                }
                for(int j = 3;j <= sqrt(num);j += 2){
                    while(num % j == 0){
                        num /= j;
                        if(mp.count(j) and mp[j] != i){
                            dsu.unionSet(mp[j], i);
                        }
                        mp[j] = i;
                    }
                }
                if(num > 1){
                    if(mp.count(num)) dsu.unionSet(mp[num], i);
                    mp[num] = i;
                    num = 1;
                }
            }
        }
        
        
        for(int i = 0;i < A.size();i++) ans = max(ans, dsu.retSize(i));
        
        return ans;
    }
};
