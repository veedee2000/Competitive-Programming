class Solution {
public:
    bool checkValidString(string s) {
        int val = 0;
        for(auto x:s){
            if(x == '(' or x == '*') val++;
            else val--;
            if(val < 0) return 0;
        }
        
        if(val == 0) return 1;
        
        reverse(s.begin(),s.end());
        
        val = 0;
        for(auto x:s){
            if(x == ')' or x == '*') val++;
            else val--;
            if(val < 0) return 0;
        }
        return 1;
    }
};
