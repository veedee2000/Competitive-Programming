class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        if(n == 0) return 0;
        int val = 0;
        for(int i=0;i<n;i++){     // For Checking odd length Palindromes
            
            int l = i, r = i;
            ++val;               // Since single characters are also palindromes
            while(l > 0 and r < n-1 and s[--l] == s[++r]){
                ++val;
            }
            
        }
         
        for(int i=0;i<n-1;i++){    // For Checking even length palindromes
            
            int l = i, r = i+1;
            if(s[l] != s[r]) continue;   
            ++val;                // For 2 character palindromes
            while(l > 0 and r < n-1 and s[--l] == s[++r]){
                ++val;
            }

        }
        
        return val;
    }
};
