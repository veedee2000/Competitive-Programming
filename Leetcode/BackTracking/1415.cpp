class Solution {
public:
    int k,c;
    string ans;
    string getHappyString(int n, int k) {
        this -> k = k;
        c = 0;
        string path = "";
        f(n,'z',path);
        return ans;
    }
    
    void f(int n,char pre,string& s){
        if(n == 0){
            if(++c == k){ ans = s; }
            return;
        }
        for(char ch = 'a';ch <= 'c';ch++){
            s.push_back(ch);
            if(ch != pre) f(n - 1,ch,s);
            s.pop_back();
        }
    }
};
