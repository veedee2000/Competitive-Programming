class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int>s;
        s.push(0);
        for(auto x:S){
            if(x == '(') s.push(0);
            else{
                int val = s.top();
                s.pop();
                s.top() += max(val * 2, 1);
            }
        }
        return s.top();
    }
};
