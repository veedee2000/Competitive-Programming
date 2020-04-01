const int mod = 1e9 + 7;

class Solution {
public:
    
    long long binExp(long long base,long long exp){
        base = base % mod;
        if(!exp) return 1;
        else if(exp == 1) return base;
        else if(exp%2) return base * binExp(base,exp - 1) % mod;
        else return binExp(base * base % mod,exp / 2);
    }
    
    int strStr(string haystack, string needle) {
        // Rabin-Karp solution
        
        int n = haystack.size(),m = needle.size();
        if(m > n) return -1;
        if(m == 0) return 0;
        long long rkNeeded = 0;
        for(int i = 0;i < m;i++){
            rkNeeded = (rkNeeded * 26 + (needle[i] - 'a' + 1)) % mod;
        }
        
        long long rk = 0,deleteExp = binExp(26,m - 1);
        for(int i = 0;i < n;i++){
            rk = (rk * 26 + (haystack[i] - 'a' + 1)) % mod;
            if(i < m - 1) continue;
            if(rk == rkNeeded and haystack.substr(i - m + 1,m) == needle){
                return i - m + 1;
            }
            
            rk = (rk - deleteExp * (haystack[i - m + 1] - 'a' + 1)) % mod;  
            if(rk < 0) rk = (rk + mod);
        }
        
        return -1;
    }
};
