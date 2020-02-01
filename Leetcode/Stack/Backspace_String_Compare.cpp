class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char>s1,s2;
        for(auto x:S){
            if(x == '#'){
                if(!s1.empty()) s1.pop();
            }
            else s1.push(x);
        }
        for(auto x:T){
            if(x == '#'){
                if(!s2.empty()) s2.pop();
            }
            else s2.push(x);
        }
        
        return (s1 == s2);
    }
};
