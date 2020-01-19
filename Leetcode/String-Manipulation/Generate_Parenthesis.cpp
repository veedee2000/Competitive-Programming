class Solution {
public:
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(n,n,s);
        return ans;
    }
    
    void backtrack(int left,int right,string s){
        if(left < 0 or right < 0) return;
        if(left == 0 and right == 0){
            ans.push_back(s);
            return;
        }
        if(right < left) return;
        backtrack(left - 1,right,s + "(");
        backtrack(left,right - 1,s + ")");
    }
};
