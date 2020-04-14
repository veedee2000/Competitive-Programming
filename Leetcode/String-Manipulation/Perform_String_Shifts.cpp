class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total = 0;
        for(auto p:shift){
            total += p[0] ? p[1] : -p[1];
        }
        total = total > 0 ? total % s.size() : (s.size() - abs(total) % s.size()) % s.size();
        while(total--){
            s.insert(0,1,s[s.size() - 1]);
            s.pop_back();
        }
        return s;
    }
};
