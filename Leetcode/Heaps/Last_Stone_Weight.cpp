class Solution {
    struct comp{
        bool operator()(const int& a,const int& b){
            return a < b;
        }
    };
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,comp>q;
        for(auto x:stones) q.push(x);
        while(q.size() > 1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(a == b) continue;
            else q.push(abs(a - b));
        }
        if(q.empty()) return 0;
        return q.top();
    }
};
