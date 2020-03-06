class Solution {
public:
    vector<string>words;
    unordered_map<int,vector<string>>mp;
    string s;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this -> s = s;
        words = wordDict;
        return f(s.size() - 1);
    }
    
    vector<string> f(int i){
        if(i == -1) return {""};
        if(mp.find(i) != mp.end()) return mp[i];
        vector<string>res;
        for(auto word:words){
            vector<string>buff;
            if(i + 1 >= word.size() and s.substr(i - word.size() + 1,word.size()) == word){
                buff = f(i - word.size());
                for(auto x:buff){
                    if(x.size()) res.push_back(x + " " + word);
                    else res.push_back(word);
                }
            }
        }
        return mp[i] = res;
    }
};
