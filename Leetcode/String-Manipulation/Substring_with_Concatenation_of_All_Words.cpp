class Solution {
public:
    unordered_map<string,int>mp;
    int sz;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if(words.size() == 0) return {};
        sz = words[0].size();
        int totalSize = sz * words.size();
        for(auto x:words) mp[x]++;
        string v;
        for(int i = 0;i < s.size();i++){
            v.push_back(s[i]);
            if(i < totalSize - 1) continue;
            if(check(v)) ans.push_back(i - totalSize + 1);
            v.erase(0,1);
        }
        return ans;
    }
    
    bool check(string v){
        unordered_map<string,int>sub = mp;
        for(int i = 0;i < v.size();i += sz){
            if(!sub.count(v.substr(i,sz)) or (--sub[v.substr(i,sz)] < 0)) return 0;
        }
        return 1;                                
    }
};
