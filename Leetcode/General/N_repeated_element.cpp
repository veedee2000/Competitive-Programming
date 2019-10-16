class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        set<int>s;
        for(auto x:a){
            if(s.count(x) == 0) s.insert(x);
            else return x;
        }
        return 0;
    }
};
