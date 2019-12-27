class Solution {
public:
    int minAddToMakeValid(string S) {
        int min_val = 0,val = 0;
        for(int i = 0;i < S.size();i++){
            if(S[i] == '(') val++;
            else {
                --val;
                min_val = min(min_val,val);
            }
        }
        if(min_val >= 0) return val;
        else return abs(val - 2*min_val);
    }
};
