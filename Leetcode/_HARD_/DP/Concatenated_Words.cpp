class Solution {
public:
    
    unordered_map<string,bool>dp;
    unordered_set<string>st;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        for(auto x:words) st.insert(x);
        for(auto word:words){
            if(f(word)) ans.push_back(word);
        }
        return ans;
    }
    
    bool f(string word){
        if(word.size() < 2) return 0; 
        if(dp.count(word)) return dp[word];
        string pre,suff = word;
        for(int i = 0;i < word.size() - 1;i++){
            pre.push_back(word[i]),suff.erase(0,1);
            if(st.count(pre)){
                if(st.count(suff) or f(suff)){
                    return dp[word] = 1;
                }
            }
        }
        return dp[word] = 0;
    }
};
