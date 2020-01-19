class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int val;
        for(auto x:s){
            if(x == '(') val++;
            else if(x == ')') val--;
            if(val < 0 and (x == '(' or x == ')')){
                val++;
                continue;
            }
            else ans += x;
        }
        int in = ans.size() - 1;
        while(val > 0){
            if(ans[in] == '('){
                ans.erase(in,1);
                val--;
            }
            in--;
        }
        return ans;
    }
};
