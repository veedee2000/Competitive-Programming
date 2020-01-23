class CombinationIterator {
public:
    vector<string>lex;
    string s;
    int len,val;
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        len = combinationLength;
        val = 0;
        backtrack(s,len,"",0);
    }
    
    string next() {
        return lex[val++];
    }
    
    bool hasNext() {
        return (val < lex.size());
    }
    
    void backtrack(string s,int len,string path,int now){
        if(len < 1){
            lex.push_back(path);
            return;
        }
        for(int i = now;i < s.size();i++){
            backtrack(s,len - 1,path + string(1,s[i]),i + 1);
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
