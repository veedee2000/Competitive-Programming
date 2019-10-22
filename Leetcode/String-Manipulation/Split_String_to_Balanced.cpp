class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0,val = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'R') val++;
            else val--;
            if(val == 0) ++ans;
        }
        return ans;
    }
};
