class Solution {
public:
    bool isValid(string S) {
        stack<char>s;
        for(auto x:S){
            if(x == 'c'){
                if(s.size() < 2) return 0;
                char b = s.top();
                s.pop();
                char a = s.top();
                s.pop();
                if(b == 'b' and a == 'a') {}
                else return 0;
            }
            else s.push(x);
        }
        return s.empty();
    }
};
