const int mod = 1000000007;

class Solution {
public:
    unordered_map<int,unordered_map<char,int>>dp;
    string vowel;
    int countVowelPermutation(int n) {
        vowel = "aeiou";
        int ans = 0;
        for(auto x:vowel) ans = (ans + f(n,x)) % mod;
        return ans;
    }
    
    int f(int n,char c){
        if(n <= 1) return 1;
        if(dp[n].count(c)) return dp[n][c];
        if(c == 'a') dp[n][c] = f(n - 1,'e') % mod;
        if(c == 'e') dp[n][c] = (f(n - 1,'a') % mod + f(n - 1,'i') % mod) % mod;
        if(c == 'i') dp[n][c] = (((f(n - 1,'a') % mod + f(n - 1,'e') % mod) % mod + f(n - 1,'o') % mod) % mod + f(n - 1,'u') % mod) % mod;
        if(c == 'o') dp[n][c] = (f(n - 1,'i') % mod + f(n - 1,'u') % mod) % mod;
        if(c == 'u') dp[n][c] = f(n - 1,'a') % mod;
        return dp[n][c];
    }
};
