class Solution {
public:
    string shortestPalindrome(string s) {
        // KMP
        if(s == "") return ""; 
        int n = 2 * s.size() + 1;
        string rev = s,modified;
        reverse(rev.begin(),rev.end());
        modified = s + "#" + rev;
        vector<int>lps(n,0);
        int i = 1,j = 0;
        while(i < n){
            if(modified[i] == modified[j]) lps[i++] = ++j;
            else if(j) j = lps[j - 1];
            else i++;
        }
        string add = s.substr(lps[n - 1]);
        reverse(add.begin(),add.end());
        return add + s;
    }
};
