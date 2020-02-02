class Solution {
public:
    unordered_map<char,vector<char>>mp;
    vector<string>ans;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o',};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        backtrack(digits,"",0);
        return ans;
    }
    
    void backtrack(string digits,string path,int i){
        if(i == digits.size()){
            ans.push_back(path);
            return;
        }
        for(auto x:mp[digits[i]]){
            path.push_back(x);
            backtrack(digits,path,i + 1);
            path.pop_back();
        }
    }
};
