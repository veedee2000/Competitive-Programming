class Solution {
public:
    vector<vector<int>>dp;
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(auto x:t){
            if(x == s[i]) i++;
            if(i == s.size()) return 1;
        }
        if(i == s.size()) return 1;
        return 0;
    }
};
