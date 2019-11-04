class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        if(n == 0) return 0;
        int val = 0;
        for(int i=0;i<n;i++){
            
            string ans = "";
            ans += s[i];
            int l = i, r = i;
            ++val;
            while(l > 0 and r < n-1 and s[--l] == s[++r]){
                ans = s[l] + ans + s[r];
                ++val;
            }
        }
        
        for(int i=0;i<n-1;i++){
            
            string ans = "";
            int l = i, r = i+1;
            if(s[l] != s[r]) continue;
            ++val;
            ans += s[l];
            ans += s[r];
            while(l > 0 and r < n-1 and s[--l] == s[++r]){
                ans = s[l] + ans + s[r];
                ++val;
            }

        }
        
        return val;
    }
};
