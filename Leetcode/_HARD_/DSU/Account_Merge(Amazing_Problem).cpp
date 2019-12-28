class Solution {
public:
    vector<int>parent,size;
    unordered_map<string,int>present;
    unordered_map<int,vector<string>>mail;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.resize(accounts.size());
        size.resize(accounts.size());
        for(int i = 0;i < accounts.size();i++){
            parent[i] = i;
            size[i] = 1;
        } 
        for(int i = 0;i < accounts.size();i++){
            for(int j = 1;j < accounts[i].size();j++){
                if(present.count(accounts[i][j])){
                    union_set(find_set(i),find_set(present[accounts[i][j]]));
                }
                present[accounts[i][j]] = i;
            }
        }
        
        vector<vector<string>>ans;
        for(auto pair:present){
            int value = find_set(pair.second);
            mail[value].push_back(pair.first);
        }
        
        for(auto pair:mail){
            vector<string>temp = pair.second;
            sort(temp.begin(),temp.end());
            temp.insert(temp.begin(),accounts[pair.first][0]);
            ans.push_back(temp);
        }
        return ans;
    }
    
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void union_set(int a,int b){
        int root_a = find_set(a);
        int root_b = find_set(b);
        if(root_a != root_b){
            if(size[a] <= size[b]){
                swap(a,b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
