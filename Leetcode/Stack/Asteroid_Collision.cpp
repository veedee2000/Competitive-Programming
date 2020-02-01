class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>ans;
        for(auto x:asteroids){
            bool flag = 0;
            while(!s.empty() and s.top() > 0 and x < 0){
                if(abs(s.top()) == abs(x)) {s.pop(); flag = 1; break;}
                else if(abs(s.top()) > abs(x)) {flag = 1; break;}
                else {s.pop();}
            }
            if(!flag) s.push(x);
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
