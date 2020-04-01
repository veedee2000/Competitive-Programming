const int mod = 1e9 + 7;

class Solution {
public:
    string shortestPalindrome(string s) {
        // Rabin-Karp
        if(s == "") return ""; 
        int ans;
        int n = s.size();
        long long hashForward = 0,hashBackward = 0,pow = 1;
        
        for(int i = 0;i < n;i++){
            hashForward = (hashForward * 256 + (int) s[i]) % mod;
            hashBackward = (hashBackward + (pow * ((int) s[i])) % mod) % mod;
            pow = (pow * 256) % mod;
            if(hashForward == hashBackward) ans = i;
        }
        string sub = s.substr(ans + 1);
        reverse(sub.begin(),sub.end());
        return sub + s;
    }
};
