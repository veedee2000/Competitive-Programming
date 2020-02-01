class Solution {
public:
    string reverseParentheses(string s) {
        int i = 0;
        string ans = "";
        stack<int>p;
        for(auto x:s){
            if(x == '(') p.push(i);
            else if(x == ')'){
                int index = p.top();
                reverse(s.begin() + index,s.begin() + i);
                p.pop();
            }
            i++;
        }
        for(auto x:s){
            if(x == '(' or x == ')') continue;
            else ans.push_back(x);
        }
        return ans;
    }
};
