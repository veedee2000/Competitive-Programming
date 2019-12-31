class Solution {
public:
    string s;
    string longestPalindrome(string s) {
        this -> s = s;
        if(s.size() < 2) return s;
        int ans = 0;
        string ret;
        for(int i = 0;i < s.size() - 1;i++){
            int val1 = f(i,i), val2 = f(i,i + 1);
            if(ans < val1){
                ans = val1;
                ret = s.substr(i - val1/2,val1);
            }
            
            if(ans < val2){
                ans = val2;
                ret = s.substr(i - val2/2 + 1,val2);
            }
        }
        return ret;
    }
    
    int f(int i,int j){
        if(i < 0 or j > s.size() - 1) return 0;
        if(s[i] != s[j]) return 0;
        if(i != j) return 2 + f(i - 1,j + 1);
        else return 1 + f(i - 1,j + 1);
    }
    
};
