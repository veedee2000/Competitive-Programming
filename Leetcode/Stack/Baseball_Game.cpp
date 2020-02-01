class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        int sum = 0;
        for(auto x:ops){
            if(x == "C") sum -= s.top(),s.pop();
            else if(x == "D") s.push(s.top() * 2),sum += s.top();
            else if(x == "+"){
                int r1 = s.top();
                s.pop();
                int r2 = s.top();
                s.push(r1);
                s.push(r1 + r2);
                sum += r1 + r2;
            }
            else s.push(stoi(x)),sum += stoi(x);
        }
        return sum;
    }
};
