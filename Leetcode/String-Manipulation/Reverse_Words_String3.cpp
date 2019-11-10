class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "",word,c = "";
        int i = 0;
        while(ss >> word){
            reverse(word.begin(),word.end());
            ans += c + word;
            c = "";
            i += word.size() ;
            while(s[i] == ' ') i++,c += " ";
        }
        return ans;
    }
};
