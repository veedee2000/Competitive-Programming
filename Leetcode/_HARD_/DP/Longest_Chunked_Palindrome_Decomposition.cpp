class Solution {
    
    const int mod = 1e9 + 7;
    
public:
    vector<vector<long long>>dp;
    string text;
    int n;
    int longestDecomposition(string text) {
        n = text.size();
        this -> text = text;
        dp.resize(n,vector<long long>(n,-1));
        return f(0,n - 1);
    }
    
    long long f(int start,int end){
        if(start > end) return 0;
        if(start == end) return 1;
        long long prefixHash = 0,suffixHash = 0,pow = 1;
        long long ans = 1;
        int auxStart = start,auxEnd = end;
        while(start < end){
            prefixHash = (prefixHash + pow * (text[start] - 'a' + 1) % mod ) % mod;
            suffixHash = (suffixHash * 256 % mod + (text[end] - 'a' + 1)) % mod;
            pow = (pow * 256) % mod;
            if(prefixHash == suffixHash){
                ans = max(ans,2 + f(start + 1,end - 1));
            }
            start++,end--;
        }
        return dp[auxStart][auxEnd] = ans; 
    }
};
