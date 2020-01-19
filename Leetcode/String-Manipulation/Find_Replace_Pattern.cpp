class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto word:words){
            unordered_map<char,char>mpPattern,mpWord;
            bool c = 1;
            for(int i = 0;i < word.size();i++){
                if(!mpPattern.count(pattern[i]) and !mpWord.count(word[i])){
                    mpPattern[pattern[i]] = word[i];
                    mpWord[word[i]] = pattern[i];
                    
                }
                else if(mpPattern[pattern[i]] != word[i] or mpWord[word[i]] != pattern[i]){
                    c = 0; break;
                }
            }
            if(c) ans.push_back(word);
        }
        return ans;
    }
};
