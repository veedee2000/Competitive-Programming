class Solution {
public:
    string removeOuterParentheses(string s) {
        bool b[s.size() + 20];
        memset(b,0,sizeof(b));
        b[0] = 1;
        int val = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(') ++val;
            if(s[i] == ')') --val;
            if(val == 0){
                b[i] = 1;
                b[i+1] = 1;
            }
        }
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(!b[i]) ans+=s[i];
        }
        return ans;
};
