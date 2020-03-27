class Solution {
public:
    const int mod = 1000000007;
    vector<long long>dp;
    int n;
    string s;
    int numDecodings(string s) {
        n = s.size();
        this -> s = s;
        dp.resize(n, -1);
        return f(0);
    }
    
    long long int f(int i){
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(i == n - 1) return (s[i] == '*' ? 9 : 1);
        if(dp[i] != -1) return dp[i];
        long long int ans = 0;
        if(s[i] == '*'){
            ans = (ans +  9 * f(i + 1) % mod) % mod;
            if(s[i + 1] == '*') ans = (ans + 15 * f(i + 2) % mod) % mod;
            else{
                if(s[i + 1] <= '6') ans = (ans + 2 * f(i + 2) % mod ) % mod;
                else ans = (ans + f(i + 2));
            }
        }
        else{
            ans += f(i + 1);
            if(s[i + 1] == '*'){
                if(s[i] == '1') ans = (ans + 9 * f(i + 2) % mod) % mod;
                if(s[i] == '2') ans = (ans + 6 * f(i + 2) % mod) % mod;
            }
            else{
                string sub;
                sub.push_back(s[i]);
                sub.push_back(s[i + 1]);
                if(stoi(sub) <= 26){
                    ans = (ans + f(i + 2) % mod) % mod;
                }
            }
        }
        return dp[i] = ans % mod;
    }
};
