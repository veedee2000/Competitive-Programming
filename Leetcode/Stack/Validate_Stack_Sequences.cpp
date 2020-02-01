class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int i = 0;
        for(auto x:pushed){
            s.push(x);
            if(s.top() == popped[i]){
                i++;
                s.pop();
                while(!s.empty() and s.top() == popped[i]) s.pop(),i++;
            }
        }
        return (s.empty());
    }
};
