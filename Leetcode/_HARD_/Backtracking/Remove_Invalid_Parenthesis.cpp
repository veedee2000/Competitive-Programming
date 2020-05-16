class Solution {
public:
    vector<string>ans;
    unordered_set<string>st;
    vector<string> removeInvalidParentheses(string s) {
        int minVal = 0,sum = 0;
        for(auto x:s){
            if(x == '(') sum++;
            else if(x == ')'){
                if(sum > 0) sum--;
                else minVal++;
            }
        }
        minVal += sum;
        string path = "";
        f(0,0,minVal,path,s);
        return ans;
    }
    
    void f(int i,int sum,int minVal,string& path,string& s){
        if(sum < 0 or minVal < 0) return;
        if(i == s.size()){ if(sum == 0 and minVal == 0 and !st.count(path)) ans.push_back(path), st.insert(path); return; }
        if(check(i,s) != 0) f(i + 1,sum,minVal - 1,path,s);
        path.push_back(s[i]);
        f(i + 1,sum + check(i,s),minVal,path,s);
        path.pop_back();
    }
    
    int check(int i,string& s){
        if(s[i] == '(') return 1;
        else if(s[i] == ')') return -1;
        else return 0;
    }
};
