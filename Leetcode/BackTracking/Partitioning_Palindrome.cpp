class Solution {
public:
    vector<vector<string>>ans;
    string s;
    vector<vector<string>> partition(string s) {
        vector<string>path;
        this -> s = s;
        f(0,path);
        return ans;
    }
    
    void f(int start,vector<string>& path){
        if(start == s.size()) { ans.push_back(path); return; }
        string put = "";
        for(int i = start;i < s.size();i++){
            put.push_back(s[i]);
            if(isPalindrome(start,i)){
                path.push_back(put);
                f(i + 1,path);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start,int end){
        while(start < end){
            if(s[start++] != s[end--]) return 0;
        }
        return 1;
    }
};
