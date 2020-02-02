struct comp {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>,comp>> m;
        for(const auto &n: nums) {
            auto &q = m[n-1];
            int h = 1;
            if(!q.empty()) {
                h = q.top() + 1; q.pop();
            }
            m[n].push(h);
        }
        for(const auto &v: m) {
            if(!v.second.empty()){
                cout<<v.first<<" "<<v.second.top()<<" "<<v.second.size()<<endl;
                if(v.second.top() < 3) return 0;
            }
        }
        return 1;
    }
};
