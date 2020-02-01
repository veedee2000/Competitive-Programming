class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int>s;
        for(auto x:S){
            if(x == '(') s.push(0);
            else{
                int a = s.top();
                s.pop();
                int n = 0;
                while(a != 0){
                    n += a;
                    a = s.top();
                    s.pop();
                }
                s.push(n == 0 ? 1 : 2 * n);
            }
        }
        int ans = 0;
        while(!s.empty()) ans += s.top(),s.pop();
        return ans;
    }
};
