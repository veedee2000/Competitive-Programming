class Solution {
public:
    bool isValid(string s) {
        stack<char>p;
        unordered_map<char,char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        for(auto x:s){
            if(mp.count(x)) p.push(x);
            else{
                if(p.empty()) return 0;
                if(mp[p.top()] == x) p.pop();
                else return 0;
            }
        }
        return p.empty();
    }
};
