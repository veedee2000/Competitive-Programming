class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP solution
        
        int n = haystack.size(),m = needle.size();
        if(m > n) return -1;
        if(n == 0) return 0;
        vector<int>lps(n,0);
        int i = 1,j = 0;
        while(i < m){
            if(needle[i] == needle[j]) lps[i++] = ++j;
            else if(j != 0) j = lps[j - 1];
            else i++;
        }
        
        i = 0,j = 0;
        while(i < n){
            if(haystack[i] == needle[j]) i++,j++;
            if(j == m) return i - j;
            if(i < n and haystack[i] != needle[j]){
                if(j) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
};IN
