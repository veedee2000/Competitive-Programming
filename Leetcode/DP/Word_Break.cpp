class Solution {
public:
    vector<int>dp;
    vector<string>words;
    string s;
    bool wordBreak(string s, vector<string>& wordDict) {
        this -> s = s;
        words = wordDict;
        dp.resize(s.size() + 1,-1);
        return f(s.size() - 1);
    }
    
    bool f(int i){
        if(i == -1) return 1;
        if(dp[i] != -1) return dp[i];
        bool ans = 0;
        for(auto word:words){
            if(word.size() <= i + 1 and s.substr(i - word.size() + 1,word.size()) == word){
                ans |= f(i - word.size());
            }
        }
        return dp[i] = ans;
    }
    
};
