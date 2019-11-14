class Solution {
public:
    unordered_map<char,int>mp;
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0;i < order.size();i++){
            mp[order[i]] = i;
        }
        for(int i = 0;i < words.size() - 1;i++){
            if(comp(words[i],words[i + 1])) continue;
            return 0;
        }
        return 1;
    }
    
    bool comp(string& a,string& b){
        for(int i = 0;i < min(a.size(),b.size());i++){
            if(a[i] == b[i]) continue;
            else return (mp[a[i]] < mp[b[i]]);
        }
        return (a.size() < b.size());
    }
};
