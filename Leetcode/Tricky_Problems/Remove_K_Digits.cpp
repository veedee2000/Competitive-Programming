class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(auto c:num){
            while(ans.size() and ans.back() > c and k){
                ans.pop_back();
                k--;
            }
            if(ans.size() or c != '0') ans.push_back(c);
        }
        while(ans.size() and k--) ans.pop_back();
        return ans.size() ? ans : "0";
    }
};
