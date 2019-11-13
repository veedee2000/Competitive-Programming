class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        if(s1.size() > s2.size()) return 0;
        for(auto x:s1){
            a[x - 'a']++;
        }
        for(int i = 0;i < s1.size() - 1;i++){
            b[s2[i] - 'a']++;
        }
        for(int i = s1.size() - 1;i < s2.size();i++){
            b[s2[i] - 'a']++;
            if(a == b) return 1;
            b[s2[i - s1.size() + 1] - 'a' ]--;
        }
        return 0;
    }
};
