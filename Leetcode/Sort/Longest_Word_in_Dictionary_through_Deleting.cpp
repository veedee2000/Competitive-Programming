class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),comp);
        for(auto x:d){
            int i = 0;
            for(int j = 0;j < s.size();j++){
                if(x[i] == s[j]) i++;
                if(i == x.size()) return x;
            }
        }
        return "";
    }
    
    bool static comp(string& a,string& b){
        if(a.size() != b.size()) return (a.size() > b.size());
        return a < b;
    }
};
