class DSU{
    
    vector<int>parent,size;
    
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
        a = findSet(a);
        b = findSet(b);
        if(a == b) return;
        if(size[b] > size[a]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
    
    int getSize(int a){
        return size[a];
    }
    
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        DSU dsu(nums.size());
        unordered_map<int,int>mp;
        
        for(int i = 0;i < nums.size();i++){
            if(mp.count(nums[i])) continue;
            if(mp.count(nums[i] - 1)) dsu.unionSet(mp[nums[i] - 1],i);
            if(mp.count(nums[i] + 1)) dsu.unionSet(mp[nums[i] + 1],i);
            mp[nums[i]] = i;
        }
        
        int ans = 0;
        
        for(int i = 0;i < nums.size();i++){
            ans = max(ans,dsu.getSize(i));
        }
        return ans;
    }
};
